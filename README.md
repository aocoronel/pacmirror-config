# Pacmirror

This repository is a personal configuration. The actual development of `pacmirror` happens [here](https://codeberg.org/aocoronel/pacmirror.c).

## How to use

```bash
❯ cc setup.c -o setup && ./setup
[GEN] flag_generator
[RUN] flag_generator
[GEN] pacmirror

❯ ./pacmirror
```

## How does it work?

`pacmirror` uses `libalpm`, which is the `pacman` database library. It compares all packages defined in `pacmirror.c` with the packages installed in the system. Then it installs missing packages from system repos and AUR (using a helper), and uninstalls packages not in the list.

## License

This repository is licensed under the MIT License, allowing for extensive use, modification, copying, and distribution.
