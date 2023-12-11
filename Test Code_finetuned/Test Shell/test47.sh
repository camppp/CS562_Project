#!/bin/bash

LIBVPX_PATH="/path/to/libvpx"

generate_rtcd_file() {
    local arch=$1
    local sym=$2
    local file=$3

    mkdir -p "$LIBVPX_PATH/gen/rtcd/$arch"

    # Generate rtcd file
    "$LIBVPX_PATH/tool/generate_rtcd" \
        --arch=$arch \
        --sym=$sym \
        --config="$LIBVPX_PATH/generate-rtcd.config" \
        "$file" \
        > "$LIBVPX_PATH/gen/rtcd/$arch/$sym.h"
}

# Usage:./generate_rtcd.sh x86_64 symbol /path/to/library/file
generate_rtcd_file "$1" "$2" "$3"