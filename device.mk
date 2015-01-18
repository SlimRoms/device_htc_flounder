#
# Copyright (C) 2013 The Android Open-Source Project
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

PRODUCT_PACKAGES := \
    libwpa_client \
    hostapd \
    wpa_supplicant \
    wpa_supplicant.conf

BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := f2fs

# This ensures the needed build tools are available.
# TODO: make non-linux builds happy with external/f2fs-tool; system/extras/f2fs_utils
ifeq ($(HOST_OS),linux)
TARGET_USERIMAGES_USE_F2FS := true
endif

LOCAL_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.flounder

TARGET_RECOVERY_FSTAB = $(LOCAL_FSTAB)

# Ramdisk
PRODUCT_PACKAGES += \
    fstab.flounder \
    init.flounder.rc \
    init.flounder.usb.rc \
    init.recovery.flounder.rc \
    ueventd.flounder.rc

# Copy flounder files as flounder64 so that ${ro.hardware} can find them
PRODUCT_PACKAGES += \
    fstab.flounder64 \
    init.flounder64.rc \
    init.flounder64.usb.rc \
    init.recovery.flounder64.rc \
    ueventd.flounder64.rc

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/touch/synaptics_dsx.idc:system/usr/idc/synaptics_dsx.idc

# headset keylayout
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/h2w_headset.kl:system/usr/keylayout/h2w_headset.kl

PRODUCT_PACKAGES += \
    libwpa_client \
    hostapd \
    dhcpcd.conf \
    wpa_supplicant \
    wpa_supplicant.conf

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/tablet_core_hardware.xml:system/etc/permissions/tablet_core_hardware.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.camera.xml:system/etc/permissions/android.hardware.camera.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:system/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.camera.full.xml:system/etc/permissions/android.hardware.camera.full.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.location.gps.xml:system/etc/permissions/android.hardware.location.gps.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:system/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.barometer.xml:system/etc/permissions/android.hardware.sensor.barometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.compass.xml:system/etc/permissions/android.hardware.sensor.compass.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:system/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.stepcounter.xml:system/etc/permissions/android.hardware.sensor.stepcounter.xml \
    frameworks/native/data/etc/android.hardware.sensor.stepdetector.xml:system/etc/permissions/android.hardware.sensor.stepdetector.xml \
    frameworks/native/data/etc/android.hardware.audio.low_latency.xml:system/etc/permissions/android.hardware.audio.low_latency.xml \
    frameworks/native/data/etc/android.hardware.nfc.xml:system/etc/permissions/android.hardware.nfc.xml \
    frameworks/native/data/etc/android.hardware.nfc.hce.xml:system/etc/permissions/android.hardware.nfc.hce.xml \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:system/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.opengles.aep.xml:system/etc/permissions/android.hardware.opengles.aep.xml \
    frameworks/native/data/etc/android.hardware.ethernet.xml:system/etc/permissions/android.hardware.ethernet.xml \
    $(LOCAL_PATH)/configs/com.nvidia.nvsi.xml:system/etc/permissions/com.nvidia.nvsi.xml

PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:system/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video.xml:system/etc/media_codecs_google_video.xml \
    frameworks/av/media/libstagefright/data/media_codecs_ffmpeg.xml:system/etc/media_codecs_ffmpeg.xml \
    $(LOCAL_PATH)/configs/media_codecs.xml:system/etc/media_codecs.xml \
    $(LOCAL_PATH)/configs/media_profiles.xml:system/etc/media_profiles.xml \
    $(LOCAL_PATH)/configs/audio_policy.conf:system/etc/audio_policy.conf \
    $(LOCAL_PATH)/configs/mixer_paths_0.xml:system/etc/mixer_paths_0.xml

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/enctune.conf:system/etc/enctune.conf

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/bluetooth/bt_vendor.conf:system/etc/bluetooth/bt_vendor.conf

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/nvaudio_conf.xml:system/etc/nvaudio_conf.xml \
    $(LOCAL_PATH)/configs/nvcamera.conf:system/etc/nvcamera.conf \
    $(LOCAL_PATH)/wifi/bcmdhd.cal:system/etc/wifi/bcmdhd.cal \
    $(LOCAL_PATH)/wifi/bcmdhd_lte.cal:system/etc/wifi/bcmdhd_lte.cal

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/gps/bcm/gps.bcm47521.conf:system/etc/gps.bcm47521.conf \
    $(LOCAL_PATH)/gps/bcm/glgps:system/bin/glgps \
    $(LOCAL_PATH)/gps/bcm/gpsconfig.xml:system/etc/gpsconfig.xml \
    $(LOCAL_PATH)/gps/bcm/lib64/gps.bcm47521.so:system/lib64/hw/gps.bcm47521.so \
    $(LOCAL_PATH)/gps/bcm/gps.bcm47521.so:system/lib/hw/gps.bcm47521.so

# GPS: QCT MODULES
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/gps/qct/gps.conf:system/etc/gps.conf \
    $(LOCAL_PATH)/gps/qct/SuplRootCert:system/etc/SuplRootCert \
    $(LOCAL_PATH)/gps/qct/libgeofence.so:system/lib/libgeofence.so \
    $(LOCAL_PATH)/gps/qct/libloc_api_v02.so:system/lib/libloc_api_v02.so \
    $(LOCAL_PATH)/gps/qct/libloc_ds_api.so:system/lib/libloc_ds_api.so \
    $(LOCAL_PATH)/gps/qct/lib64/libgeofence.so:system/lib64/libgeofence.so \
    $(LOCAL_PATH)/gps/qct/lib64/libloc_api_v02.so:system/lib64/libloc_api_v02.so \
    $(LOCAL_PATH)/gps/qct/lib64/libloc_ds_api.so:system/lib64/libloc_ds_api.so

PRODUCT_PACKAGES += \
    gps.default \
    libloc_core \
    libloc_eng \
    libgps.utils

# NFC feature + config files
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.nfc.xml:system/etc/permissions/android.hardware.nfc.xml \
    frameworks/native/data/etc/android.hardware.nfc.hce.xml:system/etc/permissions/android.hardware.nfc.hce.xml \
    device/htc/flounder/nfc/libnfc-brcm.conf:system/etc/libnfc-brcm.conf \
    device/htc/flounder/nfc/libnfc-brcm-20795a10.conf:system/etc/libnfc-brcm-20795a10.conf

PRODUCT_AAPT_CONFIG := normal large xlarge hdpi xhdpi xxhdpi
PRODUCT_AAPT_PREF_CONFIG := xhdpi

PRODUCT_CHARACTERISTICS := tablet,nosdcard

ifneq ($(filter flounder flounder64 ,$(TARGET_DEVICE)),)
# Wifi-Only overlays.
DEVICE_PACKAGE_OVERLAYS := \
    $(LOCAL_PATH)/overlays/wifi_only_overlay \
    $(LOCAL_PATH)/overlays/overlay
else
DEVICE_PACKAGE_OVERLAYS := \
    $(LOCAL_PATH)/overlays/overlay
endif

# Boot animation
TARGET_SCREEN_HEIGHT := 2048
TARGET_SCREEN_WIDTH := 1536
# no bootanim match yet so let's override it.
TARGET_BOOTANIMATION_NAME := 1080

PRODUCT_TAGS += dalvik.gc.type-precise

# NFC packages
PRODUCT_PACKAGES += \
    nfc_nci.bcm2079x.default \
    NfcNci \
    Tag \

PRODUCT_PACKAGES += \
    librs_jni \
    com.android.future.usb.accessory

PRODUCT_PACKAGES += \
    power.flounder \
    lights.flounder \
    sensors.flounder

# Filesystem management tools
PRODUCT_PACKAGES += \
    fsck.f2fs mkfs.f2fs

PRODUCT_PROPERTY_OVERRIDES += \
    wifi.interface=wlan0 \
    ro.opengles.version=196609 \
    ro.sf.lcd_density=320 \
    ro.hwui.texture_cache_size=72 \
    ro.hwui.layer_cache_size=48 \
    ro.hwui.r_buffer_cache_size=8 \
    ro.hwui.path_cache_size=32 \
    ro.hwui.gradient_cache_size=1 \
    ro.hwui.drop_shadow_cache_size=6 \
    ro.hwui.texture_cache_flushrate=0.4 \
    ro.hwui.text_small_cache_width=1024 \
    ro.hwui.text_small_cache_height=1024 \
    ro.hwui.text_large_cache_width=2048 \
    ro.hwui.text_large_cache_height=1024 \
    ro.hwui.disable_scissor_opt=true \
    ro.bt.bdaddr_path=/sys/module/flounder_bdaddress/parameters/bdaddress \
    ro.frp.pst=/dev/block/platform/sdhci-tegra.3/by-name/PST \
    ro.ril.def.agps.mode=1 \
    persist.tegra.compositor=glcomposer

# setup dalvik vm configs.
$(call inherit-product, frameworks/native/build/tablet-10in-xhdpi-2048-dalvik-heap.mk)

# set default USB configuration
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    persist.sys.usb.config=mtp,adb \
    ro.adb.secure=0

# for off charging mode
PRODUCT_PACKAGES += \
    charger \
    charger_res_images

# for audio
PRODUCT_PACKAGES += \
    audio.primary.flounder \
    audio.a2dp.default \
    audio.usb.default \
    audio.r_submix.default \
    libhtcacoustic \
    libnvvisualizer
PRODUCT_PROPERTY_OVERRIDES += \
    ro.audio.monitorRotation=true

# for sound trigger on DSP
PRODUCT_PACKAGES += \
    sound_trigger.primary.flounder

# for keyboard key mappings
PRODUCT_PACKAGES += \
	VolantisKeyboard

# for launcher layout
PRODUCT_PACKAGES += \
    VolantisLayout

# Allows healthd to boot directly from charger mode rather than initiating a reboot.
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.enable_boot_charger_mode=1

# add verity dependencies
$(call inherit-product, build/target/product/verity.mk)
PRODUCT_SYSTEM_VERITY_PARTITION := /dev/block/platform/sdhci-tegra.3/by-name/APP
PRODUCT_VENDOR_VERITY_PARTITION := /dev/block/platform/sdhci-tegra.3/by-name/VNR

$(call inherit-product-if-exists, hardware/nvidia/tegra132/tegra132.mk)
$(call inherit-product-if-exists, vendor/nvidia/proprietary-tegra132/tegra132-vendor.mk)
$(call inherit-product-if-exists, vendor/htc/flounder/device-vendor.mk)
$(call inherit-product-if-exists, hardware/broadcom/wlan/bcmdhd/firmware/bcm4354/device-bcm.mk)
$(call inherit-product-if-exists, vendor/htc/flounder/audio/lifevibes/lvve/device-vendor-lvve.mk)
$(call inherit-product-if-exists, vendor/htc/flounder/audio/tfa/device-vendor-tfa.mk)
