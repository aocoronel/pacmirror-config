/*  ____   _    ____ __  __ ___ ____  ____   ___  ____
 * |  _ \ / \  / ___|  \/  |_ _|  _ \|  _ \ / _ \|  _ \
 * | |_) / _ \| |   | |\/| || || |_) | |_) | | | | |_) |
 * |  __/ ___ \ |___| |  | || ||  _ <|  _ <| |_| |  _ <
 * |_| /_/   \_\____|_|  |_|___|_| \_\_| \_\\___/|_| \_\
 *
 * This configuration has only been tested on Artix Linux.
*/

// === Processor ===
// #define AMD
#define INTEL

// === Display ===
#define X11
// #define WAYLAND

// === WM ===
#ifdef WAYLAND
// #define HYPRLAND
#endif

// === SOFTWARE ===
#define ANYDESK
#define EMACS
// #define STEAM
// #define VIRTUAL_MACHINE

// === LANGUAGES ===
#define C
#define LUA
#define PYTHON
#define SHELL
// #define C3
// #define D
// #define GO
// #define HASKELL
// #define JS
// #define OCAML
// #define ODIN
// #define RUBY
// #define RUST
// #define ZIG

// === TMP ===
// #define TMP

// END OF DEFINES

#define PROGRAMMER_MODE
#define DESKTOP_MODE

#include "flags.h"

#include "pacmirror.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

// clang-format off
char *pacman[] = {
        // Artix specific packages
        "artix-archlinux-support dinit elogind-dinit networkmanager-dinit opendoas",
        "pipewire-dinit pipewire-pulse-dinit turnstile turnstile-dinit wireplumber-dinit",
        "wpa_supplicant-dinit archlinux-keyring zram-generator pacman-contrib",
        "ntp ntp-dinit openssh-dinit",

        "base base-devel cryptsetup efibootmgr grub linux lld llvm lvm2 mesa xfsprogs",

        "linux-firmware-atheros linux-firmware-broadcom linux-firmware-cirrus",
        "linux-firmware-intel linux-firmware-mediatek linux-firmware-other",
        "linux-firmware-radeon linux-firmware-realtek linux-firmware-whence",
        // "linux-firmware-nvidia",

        amd(linux-firmware-amdgpu lvulkan-radeon xf86-video-amdgpu),
        intel(
              intel-compute-runtime intel-gmmlib intel-ucode intel-graphics-compiler
              intel-media-driver vulkan-intel
        ),

        "bash bash-completion",
        "btop zoxide", // ripgrep
        "curl ffmpeg jq imagemagick openssh openssl sqlite ueberzugpp",
        "fastfetch",
        "fzf direnv",
        "git gnupg", // gitleaks git-filter-repo
        "libpulse pipewire pipewire-alsa pipewire-audio pipewire-jack pipewire-pulse gst-plugin-pipewire wireplumber",
        "mandoc man-pages",
        "mpv",
        "neovim",
        "opusfile libmad libvorbis wavpack",
        "pass pass-otp zbar oath-toolkit",
        "ranger",
        "restic",
        "rsync",
        "tar gzip zip unzip",
        "tree less lsof moreutils wget which",
        "ufw",
        "wpa_supplicant networkmanager",
        "zsh",
        // "android-tools gvfs gvfs-mtp mtpfs",
        // "bat eza fd sd",
        // "bluez bluez-utils",
        // "cmus playerctl",
        // "distrobox",
        // "docker docker-compose",
        // "harper",
        // "neomutt",
        // "newsboat",
        // "podman podman-compose podman-docker",
        // "prettier",
        // "rclone",
        // "yazi",

#ifdef DESKTOP_MODE
        "adwaita-cursors adwaita-icon-theme",
        "dunst libnotify",
        "gimp",
        "gnu-free-fonts noto-fonts-emoji ttf-jetbrains-mono-nerd",
        "pandoc-bin",
        "rofi",
        "wireguard-tools openresolv",
        "xdg-desktop-portal xdg-desktop-portal-gtk xdg-utils",
        "yt-dlp python-mutagen",
        "zathura zathura-pdf-mupdf",
        // "libreoffice-still hunspell",
        // "pcmanfm tumbler ffmpegthumbnailer",
        // "polkit udiskie udisks2",
        // "qutebrowser",
        // "shotcut sox",
        // "tenacity",
        // "thunderbird",
        // "wine",
        hyprland(
                cpio gsettings-desktop-schemas hyprland hyprlang libva-utils lm_sensors
                waybar wl-clipboard wlr-randr xdg-desktop-portal-hyprland hypridle hyprland-protocols
                hyprlock hyprpaper hyprpicker hyprpolkitagent hyprsunset
        ),

        virtual_machine(bridge-utils dnsmasq dosfstools libvirt lxc qemu-full swtpm virt-manager virt-viewer),

        wayland(fuzzel pavucontrol swayimg swaybg cliphist xdg-user-dirs ydotool foot),
        // wayland(grim satty slurp wf-recorder),

        x11(conky xwallpaper nsxiv zenity dconf dmenu picom redshift sxhkd xclip xdotool
            xorg-xinit xorg-xrandr xsel flameshot clipmenu
            libxft xlibre-input-elographics xlibre-input-evdev xlibre-input-joystick
            xlibre-input-keyboard xlibre-input-libinput xlibre-input-mouse xlibre-input-synaptics
            xlibre-input-vmmouse xlibre-input-void xlibre-input-wacom xlibre-video-amdgpu
            xlibre-video-ast xlibre-video-ati xlibre-video-dummy xlibre-video-fbdev
            xlibre-video-intel xlibre-video-nouveau xlibre-video-qxl xlibre-video-sisusb
            xlibre-video-vesa xlibre-video-vmware xlibre-video-voodoo xlibre-xserver
            xlibre-xserver-common xlibre-xserver-devel xlibre-xserver-xephyr xlibre-xserver-xnest
            xlibre-xserver-xvfb xorg-xset
        ),
        // x11(obs-studio),

        steam(gamemode steam),
        anydesk(minizip lsb-release),

#endif // DESKTOP_MODE

#ifdef PROGRAMMER_MODE
        c(clang gcc gdb libtool make mold valgrind tcc), // meson cmake ninja lldb
        c3(c3c),
        d(dmd dfmt),
        go(go),
        haskell(ghc),
        js(nodejs npm),
        lua(stylua),
        ocaml(ocaml),
        odin(odin odinfmt),
        ruby(ruby),
        rust(rust rust-analyzer),
        shell(shfmt), // shellcheck
        zig(zig zls),
        python(
               python imath
               pystring python-beautifulsoup4 python-dateutil python-feedgen python-lxml
               python-mutagen python-pytz python-six
        ),
#endif // PROGRAMMER_MODE

        // If EMACS is defined, install the emacs package, else assumes source compiling
#ifndef EMACS
        "hunspell-en_us aspell-pt aspell-en hunspell libxaw libotf m17n-lib libgccjit", // global
#else
        "emacs hunspell-en_us aspell aspell-pt aspell-en hunspell libxaw libotf m17n-lib libgccjit", // global
#endif

#ifdef TMP
#endif // TMP

        NULL,
};
// clang-format on

void init_aur(PackageList *aur) {
    // da_append(aur, "jmtpfs");
    // da_append(aur, "mutt-wizard");
    // da_append(aur, "steghide");
    // da_append(aur, "tomb");
    da_append(aur, "freetube-bin");
    da_append(aur, "gf2-git");
    da_append(aur, "brave-origin-bin");
    // da_append(aur, "yay-bin");

#ifdef HYPRLAND
    // da_append(aur, "wttrbar");
#endif

#ifdef ANYDESK
    da_append(aur, "anydesk-bin");
    da_append(aur, "yp-tools");
#endif
    da_append_null(aur);
}

int main(int argc, char **argv) {
    PackageList aur = { 0 };
    {
        aur = init_da();
        init_aur(&aur);
    }
    pacmirror(pacman, aur.data, argc, argv);
    da_free(&aur);
}
