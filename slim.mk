# Inherit some common CM stuff.
$(call inherit-product, vendor/slim/config/common_full_phone.mk)

# Enhanced NFC
$(call inherit-product, vendor/slim/config/nfc_enhanced.mk)

# Inherit device configuration
$(call inherit-product, device/htc/flounder/aosp_flounder.mk)

DEVICE_PACKAGE_OVERLAYS += device/htc/flounder/overlay-slim

## Device identifier. This must come after all inclusions
PRODUCT_NAME := slim_flounder
PRODUCT_BRAND := google
PRODUCT_MODEL := Nexus 9
