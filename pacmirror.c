#define ARTIX
#define BROWSER
#define C
#define IMAGE_EDITOR
#define INTEL
#define NETWORK_MANAGER
#define ODIN
#define OFFICE
#define PROPRIETARY
#define RUST
#define SCREEN_RECORDER
#define VPN
#define WINE
#define XORG
#define ZIG
#define XLIBRE
// #define ADB
// #define AMD
// #define AUDIO_EDITOR
// #define BLUETOOTH
// #define DOCKER
// #define EMACS
// #define FILE_MANAGER
// #define HYPRLAND
// #define MAIL
// #define PODMAN
// #define RSS
// #define STEAM
// #define TMP
// #define VIDEO_EDITOR
// #define VIRTUAL_MACHINE
// #define WAYLAND

// EOF DEFINES

#include "flags.h"

#include "pacmirror.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

// clang-format off
char *pacman[] = {
#ifdef TMP
#endif
#ifdef PROPRIETARY
        "minizip", // for AnyDesk
        "lsb-release",
#endif
        "adwaita-cursors adwaita-icon-theme", // Theme
        "base base-devel cryptsetup efibootmgr grub linux linux-firmware lld llvm lvm2 mesa xfsprogs", // Linux
        "bash bash-completion",
        "btop ripgrep zoxide", // Better core-utils
        // "bat eza fd sd", // Better core-utils
        "cmus opusfile libmad libvorbis wavpack playerctl", // Music Player
        "curl ffmpeg jq imagemagick openssh openssl sqlite ueberzugpp", // Libraries...
        "dunst libnotify", // Notifications
        "fastfetch", // Neofetch
        "fzf direnv",
        "git gitleaks git-filter-repo tig gnupg",
        "gnu-free-fonts noto-fonts-emoji ttf-jetbrains-mono-nerd", // Fonts
        "harper", // LSP for your grammatical mistakes
        "libpulse pipewire pipewire-alsa pipewire-audio pipewire-jack pipewire-pulse gst-plugin-pipewire wireplumber", // Audio
        "mandoc man-pages", // Manpages
        "mpv", // Media Player
        "neovim", // Text Editor
        // "nodejs npm", // JavaScript
        "pass pass-otp zbar oath-toolkit", // PasswordStore
        // "prettier", // General formatter
        "python imath",
        "restic", // Backups faster than borgbackup
        "rofi", // Dmenu from the future
        "rsync",
        "pcmanfm tumbler ffmpegthumbnailer",
        // "shellcheck", // bash-language-server
        "shfmt", // shell formatter
        "stylua",
        "pandoc-bin",
        "ntp ntp-dinit",
        "tcc",
        "tar zip unzip",
        "tree less lsof moreutils wget which", // Great ones
        "ufw", // Firewall
        "xdg-desktop-portal xdg-desktop-portal-gtk xdg-utils",
        "yt-dlp python-mutagen",
        "zathura zathura-pdf-mupdf", // PDF Viewer
        "zsh",
        "global",
        // "distrobox", // Use any distro in any distro
        // "go",
        // "polkit udiskie udisks2",
        "pystring python-beautifulsoup4 python-dateutil python-feedgen python-lxml python-mutagen python-pytz python-six",
        // "rclone",
        // "ruby",
        // browser(qutebrowser),
        // screen_recorder(obs-studio),
        adb(android-tools gvfs gvfs-mtp mtpfs),
        amd(lib32-vulkan-radeon vulkan-radeon xf86-video-amdgpu),
#if !defined(ARTIX)
        "xf86-video-intel",
#endif
        artix(
               artix-archlinux-support dinit elogind-dinit networkmanager-dinit opendoas
               pipewire-dinit pipewire-pulse-dinit turnstile turnstile-dinit wireplumber-dinit
               wpa_supplicant-dinit archlinux-keyring zram-generator pacman-contrib
        ),
        audio_editor(tenacity),
        bluetooth(bluez bluez-utils),
        browser(firefox),
        c(clang cmake gcc gdb libtool lldb make meson mold ninja valgrind),
        docker(docker docker-compose),
#ifndef EMACS
        "aspell aspell-pt aspell-en hunspell libxaw libotf m17n-lib libgccjit",
#else
        emacs(emacs aspell aspell-pt aspell-en hunspell libxaw libotf m17n-lib libgccjit),
#endif
        hyprland(
                cpio gsettings-desktop-schemas hyprland hyprlang libva-utils lm_sensors
                waybar wl-clipboard wlr-randr xdg-desktop-portal-hyprland hypridle hyprland-protocols
                hyprlock hyprpaper hyprpicker hyprpolkitagent hyprsunset
        ),
        intel(
                intel-compute-runtime intel-gmmlib intel-ucode intel-graphics-compiler
                intel-media-driver lib32-vulkan-intel vulkan-intel
        ),
        file_manager(ranger, yazi),
        image_editor(gimp),
        xlibre(conky libxft xlibre-input-elographics xlibre-input-evdev xlibre-input-joystick xlibre-input-keyboard xlibre-input-libinput xlibre-input-mouse xlibre-input-synaptics xlibre-input-vmmouse xlibre-input-void xlibre-input-wacom xlibre-video-amdgpu xlibre-video-ast xlibre-video-ati xlibre-video-dummy xlibre-video-fbdev xlibre-video-intel xlibre-video-nouveau xlibre-video-qxl xlibre-video-sisusb xlibre-video-vesa xlibre-video-vmware xlibre-video-voodoo xlibre-xserver xlibre-xserver-common xlibre-xserver-devel xlibre-xserver-xephyr xlibre-xserver-xnest xlibre-xserver-xvfb xorg-xset),
        mail(neomutt),
        network_manager(wpa_supplicant networkmanager),
        office(libreoffice-still hunspell),
        podman(podman podman-compose podman-docker),
        rss(newsboat),
        rust(rustup rust-analyzer),
        steam(gamemode steam),
        video_editor(shotcut sox),
        odin(odin),
        virtual_machine(bridge-utils dnsmasq dosfstools libvirt lxc qemu-full swtpm virt-manager virt-viewer),
        wayland(fuzzel pavucontrol swayimg swaybg cliphist xdg-user-dirs ydotool foot),
        wine(wine),
        vpn(wireguard-tools openresolv),
        xorg(xwallpaper nsxiv zenity dconf dmenu picom redshift sxhkd xclip xdotool xorg-xinit xorg-xrandr xsel flameshot clipmenu),
        zig(zig zls),
#ifdef WAYLAND
        screen_recorder(grim satty slurp wf-recorder),
#endif
        NULL,
};

// char *aur[] = {
//         "freetube-bin",
//         "lesspass",
//         // "pass-tomb",
//         // "steghide",
//         // "tomb",
//         "yay-bin",
//         adb(jmtpfs),
//         hyprland(wttrbar),
//         mail(mutt-wizard),
//         NULL,
// };
// clang-format on

void init_aur(DynArray *aur) {
        init_da(aur);
        da_append(aur, "freetube-bin");
        da_append(aur, "lesspass");
        da_append(aur, "yay-bin");
        da_append(aur, "gf2-git");
#ifdef PROPRIETARY
        da_append(aur, "anydesk-bin");
        da_append(aur, "yp-tools");
#endif
        da_append_null(aur);
}

int main(int argc, char **argv) {
        DynArray aur = { 0 };
        init_aur(&aur);
        strcpy(AUR_HELPER, "yay");
        pacmirror(pacman, aur.data, argc, argv);
        da_free(aur);
        free(aur.data);
}
