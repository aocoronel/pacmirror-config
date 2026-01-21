#ifdef ARCH
#define arch(...) #__VA_ARGS__
#else
#define arch(...) "0"
#endif

#ifdef ARTIX
#define artix(...) #__VA_ARGS__
#else
#define artix(...) "0"
#endif

#ifdef ADB
#define adb(...) #__VA_ARGS__
#else
#define adb(...) "0"
#endif

#ifdef DOCKER
#define docker(...) #__VA_ARGS__
#else
#define docker(...) "0"
#endif

#ifdef PODMAN
#define podman(...) #__VA_ARGS__
#else
#define podman(...) "0"
#endif

#ifdef WINE
#define wine(...) #__VA_ARGS__
#else
#define wine(...) "0"
#endif

#ifdef BROWSER
#define browser(...) #__VA_ARGS__
#else
#define browser(...) "0"
#endif

#ifdef AUDIO_EDITOR
#define audio_editor(...) #__VA_ARGS__
#else
#define audio_editor(...) "0"
#endif

#ifdef EMACS
#define emacs(...) #__VA_ARGS__
#else
#define emacs(...) "0"
#endif

#ifdef SCREEN_RECORDER
#define screen_recorder(...) #__VA_ARGS__
#else
#define screen_recorder(...) "0"
#endif

#ifdef STEAM
#define steam(...) #__VA_ARGS__
#else
#define steam(...) "0"
#endif

#ifdef VIDEO_EDITOR
#define video_editor(...) #__VA_ARGS__
#else
#define video_editor(...) "0"
#endif

#ifdef IMAGE_EDITOR
#define image_editor(...) #__VA_ARGS__
#else
#define image_editor(...) "0"
#endif

#ifdef OFFICE
#define office(...) #__VA_ARGS__
#else
#define office(...) "0"
#endif

#ifdef FILE_MANAGER
#define file_manager(...) #__VA_ARGS__
#else
#define file_manager(...) "0"
#endif

#ifdef MAIL
#define mail(...) #__VA_ARGS__
#else
#define mail(...) "0"
#endif

#ifdef RSS
#define rss(...) #__VA_ARGS__
#else
#define rss(...) "0"
#endif

#ifdef VIRTUAL_MACHINE
#define virtual_machine(...) #__VA_ARGS__
#else
#define virtual_machine(...) "0"
#endif

#ifdef XORG
#define xorg(...) #__VA_ARGS__
#else
#define xorg(...) "0"
#endif

#ifdef WAYLAND
#define wayland(...) #__VA_ARGS__
#else
#define wayland(...) "0"
#endif

#ifdef HYPRLAND
#define hyprland(...) #__VA_ARGS__
#else
#define hyprland(...) "0"
#endif

#ifdef AMD
#define amd(...) #__VA_ARGS__
#else
#define amd(...) "0"
#endif

#ifdef BLUETOOTH
#define bluetooth(...) #__VA_ARGS__
#else
#define bluetooth(...) "0"
#endif

#ifdef INTEL
#define intel(...) #__VA_ARGS__
#else
#define intel(...) "0"
#endif

#ifdef NETWORK_MANAGER
#define network_manager(...) #__VA_ARGS__
#else
#define network_manager(...) "0"
#endif

#ifdef C
#define c(...) #__VA_ARGS__
#else
#define c(...) "0"
#endif

#ifdef RUBY
#define ruby(...) #__VA_ARGS__
#else
#define ruby(...) "0"
#endif

#ifdef ZIG
#define zig(...) #__VA_ARGS__
#else
#define zig(...) "0"
#endif

#ifdef RUST
#define rust(...) #__VA_ARGS__
#else
#define rust(...) "0"
#endif

#ifdef JS
#define js(...) #__VA_ARGS__
#else
#define js(...) "0"
#endif

#if defined(ARTIX) && defined (XORG)
#define xlibre(...) #__VA_ARGS__
#else
#ifdef XORG
#endif
#define xlibre(...) "xorg-server"
#endif
