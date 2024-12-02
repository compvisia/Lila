#include "Perspective.h"

namespace Lila {

PerspectiveCamera::PerspectiveCamera(f32 fov, f32 aspectRatio, f32 near, f32 far) {
    changeProjection(fov, aspectRatio, near, far);
}

void PerspectiveCamera::changeProjection(f32 fov, f32 aspectRatio, f32 near, f32 far) {
    projection_m.perspective(fov, aspectRatio, near, far);
}

}