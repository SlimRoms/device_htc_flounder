/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cutils/log.h>

#include <inttypes.h>
#include <cstdlib>
#include <new>
#include <array>

#include "hwc2.h"

static int hwc2_device_open(const struct hw_module_t *module, const char *name,
    struct hw_device_t **device);

static int32_t hwc2_device_close(struct hw_device_t *device);

static struct hw_module_methods_t hwc2_module_methods = {
    .open = hwc2_device_open
};

hw_module_t HAL_MODULE_INFO_SYM = {
    .tag = HARDWARE_MODULE_TAG,
    .id = HWC_HARDWARE_MODULE_ID,
    .name = "NVIDIA Tegra hwcomposer module",
    .author = "AOSP",
    .methods = &hwc2_module_methods,
};


hwc2_error_t create_virtual_display(hwc2_device_t *device, uint32_t width,
        uint32_t height, android_pixel_format_t *format,
        hwc2_display_t *out_display)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->create_virtual_display(width, height, format, out_display);
}

hwc2_error_t destroy_virtual_display(hwc2_device_t *device,
        hwc2_display_t display)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->destroy_virtual_display(display);
}

void dump(hwc2_device_t *device, uint32_t *out_size, char *out_buffer)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    dev->dump_hwc2(out_size, out_buffer);
}

uint32_t get_max_virtual_display_count(hwc2_device_t *device)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_max_virtual_display_count();
}

hwc2_error_t register_callback(hwc2_device_t *device,
        hwc2_callback_descriptor_t descriptor,
        hwc2_callback_data_t callback_data, hwc2_function_pointer_t pointer)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->register_callback(descriptor, callback_data, pointer);
}

hwc2_error_t accept_display_changes(hwc2_device_t *device,
        hwc2_display_t display)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->accept_display_changes(display);
}

hwc2_error_t create_layer(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t *out_layer)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->create_layer(display, out_layer);
}

hwc2_error_t destroy_layer(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->destroy_layer(display, layer);
}

hwc2_error_t get_active_config(hwc2_device_t *device, hwc2_display_t display,
        hwc2_config_t *out_config)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_active_config(display, out_config);
}

hwc2_error_t get_changed_composition_types(hwc2_device_t *device,
        hwc2_display_t display, uint32_t *out_num_elements,
        hwc2_layer_t *out_layers, hwc2_composition_t *out_types)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_changed_composition_types(display, out_num_elements,
            out_layers, out_types);
}

hwc2_error_t get_client_target_support(hwc2_device_t *device,
        hwc2_display_t display, uint32_t width, uint32_t height,
        android_pixel_format_t format, android_dataspace_t dataspace)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_client_target_support(display, width, height, format,
            dataspace);
}

hwc2_error_t get_color_modes(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_num_modes, android_color_mode_t *out_modes)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_color_modes(display, out_num_modes, out_modes);
}

hwc2_error_t get_display_attribute(hwc2_device_t *device,
        hwc2_display_t display, hwc2_config_t config,
        hwc2_attribute_t attribute, int32_t *out_value)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_display_attribute(display, config, attribute, out_value);
}

hwc2_error_t get_display_configs(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_num_configs, hwc2_config_t *out_configs)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_display_configs(display, out_num_configs, out_configs);
}

hwc2_error_t get_display_name(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_size, char *out_name)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_display_name(display, out_size, out_name);
}

hwc2_error_t get_display_requests(hwc2_device_t *device, hwc2_display_t display,
        hwc2_display_request_t *out_display_requests,
        uint32_t *out_num_elements, hwc2_layer_t *out_layers,
        hwc2_layer_request_t *out_layer_requests)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_display_requests(display, out_display_requests,
            out_num_elements, out_layers, out_layer_requests);
}

hwc2_error_t get_display_type(hwc2_device_t *device, hwc2_display_t display,
        hwc2_display_type_t *out_type)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_display_type(display, out_type);
}

hwc2_error_t get_doze_support(hwc2_device_t *device, hwc2_display_t display,
        int32_t *out_support)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_doze_support(display, out_support);
}

hwc2_error_t get_hdr_capabilities(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_num_types, android_hdr_t *out_types,
        float *out_max_luminance, float *out_max_average_luminance,
        float *out_min_luminance)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_hdr_capabilities(display, out_num_types, out_types,
            out_max_luminance, out_max_average_luminance, out_min_luminance);
}

hwc2_error_t get_release_fences(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_num_elements, hwc2_layer_t *out_layers,
        int32_t *out_fences)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->get_release_fences(display, out_num_elements, out_layers,
            out_fences);
}

hwc2_error_t present_display(hwc2_device_t *device, hwc2_display_t display,
        int32_t *out_present_fence)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->present_display(display, out_present_fence);
}

hwc2_error_t set_active_config(hwc2_device_t *device, hwc2_display_t display,
        hwc2_config_t config)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_active_config(display, config);
}

hwc2_error_t set_client_target(hwc2_device_t *device, hwc2_display_t display,
        buffer_handle_t target, int32_t acquire_fence,
        android_dataspace_t dataspace, hwc_region_t damage)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_client_target(display, target, acquire_fence, dataspace,
            damage);
}

hwc2_error_t set_color_mode(hwc2_device_t *device, hwc2_display_t display,
        android_color_mode_t mode)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_color_mode(display, mode);
}

hwc2_error_t set_color_transform(hwc2_device_t *device, hwc2_display_t display,
        const float *matrix, android_color_transform_t hint)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_color_transform(display, matrix, hint);
}

hwc2_error_t set_output_buffer(hwc2_device_t *device, hwc2_display_t display,
        buffer_handle_t buffer, int32_t release_fence)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_output_buffer(display, buffer, release_fence);
}

hwc2_error_t set_power_mode(hwc2_device_t *device, hwc2_display_t display,
        hwc2_power_mode_t mode)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_power_mode(display, mode);
}

hwc2_error_t set_vsync_enabled(hwc2_device_t *device, hwc2_display_t display,
        hwc2_vsync_t enabled)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_vsync_enabled(display, static_cast<hwc2_vsync_t>(enabled));
}

hwc2_error_t validate_display(hwc2_device_t *device, hwc2_display_t display,
        uint32_t *out_num_types, uint32_t *out_num_requests)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->validate_display(display, out_num_types, out_num_requests);
}

hwc2_error_t set_cursor_position(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, int32_t x, int32_t y)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_cursor_position(display, layer, x, y);
}

hwc2_error_t set_layer_buffer(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, buffer_handle_t buffer, int32_t acquire_fence)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_buffer(display, layer, buffer, acquire_fence);
}

hwc2_error_t set_layer_surface_damage(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, hwc_region_t damage)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_surface_damage(display, layer, damage);
}

hwc2_error_t set_layer_blend_mode(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, hwc2_blend_mode_t mode)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_blend_mode(display, layer, mode);
}

hwc2_error_t set_layer_color(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer,
        hwc_color_t color)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_color(display, layer, color);
}

hwc2_error_t set_layer_composition_type(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, hwc2_composition_t type)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_composition_type(display, layer, type);
}

hwc2_error_t set_layer_dataspace(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, android_dataspace_t dataspace)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_dataspace(display, layer, dataspace);
}

hwc2_error_t set_layer_display_frame(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, hwc_rect_t frame)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_display_frame(display, layer, frame);
}

hwc2_error_t set_layer_plane_alpha(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, float alpha)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_plane_alpha(display, layer, alpha);
}

hwc2_error_t set_layer_source_crop(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, hwc_frect_t crop)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_source_crop(display, layer, crop);
}

hwc2_error_t set_layer_transform(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, hwc_transform_t transform)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_transform(display, layer, transform);
}

hwc2_error_t set_layer_visible_region(hwc2_device_t *device,
        hwc2_display_t display, hwc2_layer_t layer, hwc_region_t visible)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_visible_region(display, layer, visible);
}

hwc2_error_t set_layer_z_order(hwc2_device_t *device, hwc2_display_t display,
        hwc2_layer_t layer, uint32_t z)
{
    hwc2_dev *dev = reinterpret_cast<hwc2_context *>(device)->hwc2_dev;
    return dev->set_layer_z_order(display, layer, z);
}

/* Indexed using the hwc2_function_descriptor_t enum to find the corresponding
 * function */
static const std::array<hwc2_function_pointer_t, 44> hwc2_func_ptrs = {{
    /* Index 0 corresponds to HWC2_FUNCTION_INVALID */
    (hwc2_function_pointer_t) nullptr,
    (hwc2_function_pointer_t) accept_display_changes,
    (hwc2_function_pointer_t) create_layer,
    (hwc2_function_pointer_t) create_virtual_display,
    (hwc2_function_pointer_t) destroy_layer,
    (hwc2_function_pointer_t) destroy_virtual_display,
    (hwc2_function_pointer_t) dump,
    (hwc2_function_pointer_t) get_active_config,
    (hwc2_function_pointer_t) get_changed_composition_types,
    (hwc2_function_pointer_t) get_client_target_support,
    (hwc2_function_pointer_t) get_color_modes,
    (hwc2_function_pointer_t) get_display_attribute,
    (hwc2_function_pointer_t) get_display_configs,
    (hwc2_function_pointer_t) get_display_name,
    (hwc2_function_pointer_t) get_display_requests,
    (hwc2_function_pointer_t) get_display_type,
    (hwc2_function_pointer_t) get_doze_support,
    (hwc2_function_pointer_t) get_hdr_capabilities,
    (hwc2_function_pointer_t) get_max_virtual_display_count,
    (hwc2_function_pointer_t) get_release_fences,
    (hwc2_function_pointer_t) present_display,
    (hwc2_function_pointer_t) register_callback,
    (hwc2_function_pointer_t) set_active_config,
    (hwc2_function_pointer_t) set_client_target,
    (hwc2_function_pointer_t) set_color_mode,
    (hwc2_function_pointer_t) set_color_transform,
    (hwc2_function_pointer_t) set_cursor_position,
    (hwc2_function_pointer_t) set_layer_blend_mode,
    (hwc2_function_pointer_t) set_layer_buffer,
    (hwc2_function_pointer_t) set_layer_color,
    (hwc2_function_pointer_t) set_layer_composition_type,
    (hwc2_function_pointer_t) set_layer_dataspace,
    (hwc2_function_pointer_t) set_layer_display_frame,
    (hwc2_function_pointer_t) set_layer_plane_alpha,
    (hwc2_function_pointer_t) nullptr, /*set_layer_sideband_stream unsupported*/
    (hwc2_function_pointer_t) set_layer_source_crop,
    (hwc2_function_pointer_t) set_layer_surface_damage,
    (hwc2_function_pointer_t) set_layer_transform,
    (hwc2_function_pointer_t) set_layer_visible_region,
    (hwc2_function_pointer_t) set_layer_z_order,
    (hwc2_function_pointer_t) set_output_buffer,
    (hwc2_function_pointer_t) set_power_mode,
    (hwc2_function_pointer_t) set_vsync_enabled,
    (hwc2_function_pointer_t) validate_display,
}};

hwc2_function_pointer_t get_function(struct hwc2_device* /*device*/,
        /*hwc2_function_descriptor_t*/ int32_t descriptor)
{
    if (descriptor == HWC2_FUNCTION_INVALID ||
            static_cast<size_t>(descriptor) >= hwc2_func_ptrs.size()) {
        ALOGW("invalid descriptor");
        return nullptr;
    }
    return hwc2_func_ptrs[descriptor];
}

void get_capabilities(struct hwc2_device* /*device*/, uint32_t *out_count,
        /*hwc2_capability_t*/ int32_t* /*outCapabilities*/)
{
    *out_count = 0;
}

static int32_t hwc2_device_close(struct hw_device_t *device)
{
    hwc2_context *ctx = reinterpret_cast<hwc2_context *>(device);
    delete ctx->hwc2_dev;
    delete ctx;
    return 0;
}

static int hwc2_device_open(const struct hw_module_t *module, const char *name,
        struct hw_device_t **hw_device)
{
    if (strcmp(name, HWC_HARDWARE_COMPOSER))
        return -EINVAL;

    hwc2_context *ctx = new hwc2_context();
    if (!ctx) {
        ALOGE("failed to allocate hwc2_context");
        return -ENOMEM;
    }

    ctx->hwc2_device.common.tag = HARDWARE_DEVICE_TAG;
    ctx->hwc2_device.common.version = HWC_DEVICE_API_VERSION_2_0;
    ctx->hwc2_device.common.module = const_cast<hw_module_t *>(module);
    ctx->hwc2_device.common.close = hwc2_device_close;
    ctx->hwc2_device.getFunction = get_function;
    ctx->hwc2_device.getCapabilities = get_capabilities;

    ctx->hwc2_dev = new hwc2_dev();
    if (!ctx->hwc2_dev) {
        ALOGE("failed to allocate hwc2_dev");
        delete ctx;
        return -ENOMEM;
    }

    int ret = ctx->hwc2_dev->open_adf_device();
    if (ret < 0) {
        ALOGE("failed to open adf device: %s", strerror(ret));
        delete ctx->hwc2_dev;
        delete ctx;
        return ret;
    }

    *hw_device = &ctx->hwc2_device.common;

    return 0;
}
