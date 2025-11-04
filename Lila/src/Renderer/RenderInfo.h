#pragma once

#include "Platform/Platform.h"

#include "Common/Types.h"

namespace Lila {

    enum class RenderApi {
        None,
        OpenGL
    };

    struct RenderProfile {
        RenderApi renderApi = RenderApi::None;
        u64 deviceId = 0;
        u8 platform = LILA_ACTIVE_PLATFORM;
    };

} // namespace Lila
