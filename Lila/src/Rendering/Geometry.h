#pragma once

namespace Lila {

    class Geometry {
    public:
        virtual void render() = 0;
        virtual void destroy() = 0;
    };

} // namespace Lila
