#pragma once

namespace Lila {

    class Geometry {
    public:
        virtual ~Geometry() = default;

        virtual void render() = 0;
        virtual void destroy() = 0;
    };

} // namespace Lila
