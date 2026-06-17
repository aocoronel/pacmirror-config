#!/usr/bin/env python3

import datetime
import requests
import subprocess

AUR_RPC = "https://aur.archlinux.org/rpc/v5/info"

def vercmp(local, remote):
    return int(
        subprocess.check_output(
            ["vercmp", local, remote],
            text=True,
        ).strip()
    )

def installed_version(pkg):
    r = subprocess.run(
        ["pacman", "-Q", pkg],
        capture_output=True,
        text=True,
    )

    if r.returncode != 0:
        return None

    return r.stdout.split()[1]

def aur_version(pkg):
    r = requests.get(
        AUR_RPC,
        params={"arg[]": pkg},
        timeout=10,
    )
    r.raise_for_status()

    data = r.json()

    if data["resultcount"] == 0:
        return None

    return data["results"][0]["Version"]

def arch_version(pkg):
    r = requests.get(
        f"https://archlinux.org/packages/search/json/?name={pkg}",
        timeout=10,
    )
    r.raise_for_status()

    results = r.json()["results"]

    if not results:
        return None

    pkginfo = results[0]
    return f'{pkginfo["pkgver"]}-{pkginfo["pkgrel"]}'

def github_version(repo):
    r = requests.get(
        f"https://api.github.com/repos/{repo}/releases/latest",
        timeout=10,
        headers={"Accept": "application/vnd.github+json"},
    )

    if r.status_code == 404:
        return None

    r.raise_for_status()

    data = r.json()

    version = data["tag_name"]

    if version.startswith("v"):
        version = version[1:]

    return version

def remote_version(kind, name):
    if kind == "aur":
        return aur_version(name)

    if kind == "arch":
        return arch_version(name)

    if kind == "github":
        return github_version(name)

    raise ValueError(f"unknown source type: {kind}")

def local_package_name(kind, name):
    if kind in ("aur", "arch"):
        return name

    if kind == "github":
        return name.rsplit("/", 1)[1]

    return name

def run_once_per_day():
    today = datetime.datetime.today().strftime("%Y-%m-%d")

    try:
        with open("news.last", "r") as f:
            last = f.read().strip()
    except FileNotFoundError:
        last = None

    if last == today:
        print(
            "You have already ran news.py today. Be kind to the API providers and don't spam them. "
            "If you really want to repeat, please delete the 'news.last' file and retry."
        )
        exit(0)

    with open("news.last", "w") as f:
        f.write(today)

def main():
    run_once_per_day()

    updates = []

    with open("news") as f:
        entries = [
            line.strip()
            for line in f
            if line.strip() and not line.startswith("#")
        ]

    for entry in entries:
        try:
            kind, name = entry.split(":", 1)
        except ValueError:
            print(f"invalid entry: {entry}")
            continue

        pkgname = local_package_name(kind, name)

        local = installed_version(pkgname)
        remote = remote_version(kind, name)

        if remote is None:
            print(f"{entry}: unable to determine latest version")
            continue

        if local is None:
            print(f"{pkgname}: not installed (latest {remote})")
            continue

        try:
            cmp = vercmp(local, remote)
        except Exception:
            if local != remote:
                updates.append((pkgname, local, remote))
            continue

        if cmp < 0:
            updates.append((pkgname, local, remote))

    if not updates:
        print("No updates.")
        return

    print("Updates:")
    for pkg, local, remote in sorted(updates):
        print(f"  {pkg}: {local} -> {remote}")

if __name__ != "__main__":
    print("The file 'news.py' is not a library")
    exit(1)

main()
