#!/usr/bin/env sh

set -xe

CFLAGS="-Wall -Wextra"

cc $CFLAGS flag_generator.c -o flag_generator
./flag_generator
cc $CFLAGS pacmirror.c -o pacmirror -lalpm -DARCH -DMULTILIB -DARTIX
