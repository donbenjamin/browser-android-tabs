// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_OZONE_H_
#define COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_OZONE_H_

#include <memory>

#include "base/macros.h"
#include "components/viz/service/display/software_output_device.h"
#include "components/viz/service/viz_service_export.h"
#include "ui/gfx/native_widget_types.h"

namespace ui {
class SurfaceOzoneCanvas;
}

namespace viz {

// Ozone implementation which relies on software rendering. Ozone will present
// an accelerated widget as a SkCanvas. SoftwareOutputDevice will then use the
// Ozone provided canvas to draw.
class VIZ_SERVICE_EXPORT SoftwareOutputDeviceOzone
    : public SoftwareOutputDevice {
 public:
  explicit SoftwareOutputDeviceOzone(
      std::unique_ptr<ui::SurfaceOzoneCanvas> surface_ozone);
  ~SoftwareOutputDeviceOzone() override;

  void Resize(const gfx::Size& viewport_pixel_size,
              float scale_factor) override;
  SkCanvas* BeginPaint(const gfx::Rect& damage_rect) override;
  void EndPaint() override;

 private:
  std::unique_ptr<ui::SurfaceOzoneCanvas> surface_ozone_;

  DISALLOW_COPY_AND_ASSIGN(SoftwareOutputDeviceOzone);
};

}  // namespace viz

#endif  // COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_OZONE_H_
