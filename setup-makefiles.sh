#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

set -e

if [ -z "$DEVICE" ]; then
    DEVICE=flounder
fi
DEVICE_COMMON=flounder-common
VENDOR=htc

INITIAL_COPYRIGHT_YEAR=2016

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$MY_DIR" ]]; then MY_DIR="$PWD"; fi

SLIM_ROOT="$MY_DIR"/../../..

HELPER="$SLIM_ROOT"/vendor/slim/build/tools/extract_utils.sh
if [ ! -f "$HELPER" ]; then
    echo "Unable to find helper script at $HELPER"
    exit 1
fi
. "$HELPER"

# Initialize the helper for common device
setup_vendor "$DEVICE_COMMON" "$VENDOR" "$SLIM_ROOT" true

# Copyright headers and common guards
write_headers "flounder flounder_lte"

# Generate Treble compatible makefiles
write_makefiles "$MY_DIR"/common-proprietary-files.txt true

write_footers

if [ -s "$MY_DIR"/proprietary-files.txt ] || [ -s "$MY_DIR"/../$DEVICE/device-proprietary-files.txt ]; then
    # Reinitialize the helper for device
    setup_vendor "$DEVICE" "$VENDOR" "$SLIM_ROOT"

    # Copyright headers and guards
    write_headers

    # Generate Treble compatible makefiles
    write_makefiles "$MY_DIR"/proprietary-files.txt true
    write_makefiles "$MY_DIR"/../$DEVICE/device-proprietary-files.txt true

    write_footers
fi