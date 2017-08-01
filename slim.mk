# Release name
PRODUCT_RELEASE_NAME := flounder

# Boot animation
TARGET_SCREEN_HEIGHT := 2560
TARGET_SCREEN_WIDTH := 1536

# Inherit some common Slim stuff.
$(call inherit-product, vendor/slim/config/common.mk)

# Inherit device configuration
$(call inherit-product, device/htc/flounder/aosp_flounder.mk)

# Wifi only overlays
DEVICE_PACKAGE_OVERLAYS += device/htc/flounder/wifi_only_overlay

## Device identifier. This must come after all inclusions
PRODUCT_NAME := slim_flounder
PRODUCT_BRAND := google
PRODUCT_MODEL := Nexus 9

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=flounder \
    BUILD_FINGERPRINT=google/volantis/flounder:7.1.1/N9F27F/4072790:user/release-keys \
    PRIVATE_BUILD_DESC="volantis-user 7.1.1 N9F27F 4072790 release-keys"
