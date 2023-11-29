#pragma once

namespace Lila {

    class Vec2 {
    public:
        Vec2(float x, float y) { vec[0] = x; vec[1] = y; };

        float X() { return vec[0]; }
        float Y() { return vec[1]; }

        void setX(float x) { vec[0] = x; }
        void setY(float y) { vec[1] = y; }

        float* toArray() {
            return vec;
        }

    private:
        float vec[2] { 0.0f, 0.0f };
    };

    class Vec3 {
    public:
        Vec3(float x, float y, float z) { vec[0] = x; vec[1] = y; vec[2] = z; };

        float X() { return vec[0]; }
        float Y() { return vec[1]; }
        float Z() { return vec[2]; }

        void setX(float x) { vec[0] = x; }
        void setY(float y) { vec[1] = y; }
        void setZ(float z) { vec[2] = z; }

        float* toArray() {
            return vec;
        }

    private:
        float vec[3] { 0.0f, 0.0f, 0.0f };
    };

    class Vec4 {
    public:
        Vec4(float x, float y, float z, float w) { vec[0] = x; vec[1] = y; vec[2] = z; vec[3] = w; };

        float X() { return vec[0]; }
        float Y() { return vec[1]; }
        float Z() { return vec[2]; }
        float W() { return vec[3]; }

        void setX(float x) { vec[0] = x; }
        void setY(float y) { vec[1] = y; }
        void setZ(float z) { vec[2] = z; }
        void setW(float w) { vec[3] = w; }

        float* toArray() {
            return vec;
        }

    private:
        float vec[4] { 0.0f, 0.0f, 0.0f, 0.0f };
    };

}