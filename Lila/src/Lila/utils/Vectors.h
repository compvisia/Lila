#pragma once

namespace Lila {

class Vec2 {
public:
    Vec2(float x, float y) { this->x = x; this->y = y; };

    float X() { return x; }
    float Y() { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

private:
    float x, y;
};

class Vec3 {
public:
    Vec3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; };

    float X() { return x; }
    float Y() { return y; }
    float Z() { return z; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

private:
    float x, y, z;
};

class Vec4 {
public:
    Vec4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; };

    float X() { return x; }
    float Y() { return y; }
    float Z() { return z; }
    float W() { return w; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }
    void setW(float w) { this->w = w; }

private:
    float x, y, z, w;
};

}