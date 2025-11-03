#pragma once

namespace Lila {

    class Texture {
    public:
        virtual void bind() = 0;
        virtual void unbind() = 0;

        virtual void destroy() = 0;
    };

} // namespace Lila
