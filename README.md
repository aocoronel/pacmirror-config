# Pacmirror

This repository is a personal configuration. The actual development of `pacmirror` happens [here](https://codeberg.org/aocoronel/pacmirror.c).

## How to use

```bash
❯ ./setup.sh
+ CFLAGS='-Wall -Wextra'
+ cc -Wall -Wextra flag_generator.c -o flag_generator
+ ./flag_generator
+ cc -Wall -Wextra pacmirror.c -o pacmirror -lalpm -DARCH -DMULTILIB -DARTIX

❯ ./pacmirror
```

## How does it work?

`pacmirror` uses `libalpm`, which is the `pacman` database library. It compares all packages defined in `pacmirror.c` with the packages installed in the system. Then it installs missing packages from system repos and AUR (using a PKGBUILDs in `./pkg`), and uninstalls packages not in the list.

## License

This repository is licensed through the GNU General Public License, version 2 or later.
