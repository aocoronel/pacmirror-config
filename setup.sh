#!/usr/bin/env sh

CFLAGS="-Wall -Wextra"
DEFINES="-lalpm -DARCH -DMULTILIB -DARTIX"

set -xe

cc $CFLAGS flag_generator.c -o flag_generator
./flag_generator
cc $CFLAGS $DEFINES pacmirror.c -o pacmirror
