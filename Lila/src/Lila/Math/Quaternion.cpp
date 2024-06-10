#include "Quaternion.h"

#include "Math.h"

namespace Lila
{
    
/**
 * @brief Makes a identity quaternion.
*/
Quaternion::Quaternion() {
    h = 1;
    i = j = k = 0;
}

/**
 * @brief Makes a quaternion from a Vec4 using the ijkh format.
 * 
 * @param vec Must be in the hijk format.
*/
Quaternion::Quaternion(Vec4& vec) {
    h = vec.x();
    i = vec.y();
    j = vec.z();
    k = vec.w();
}

/**
 * @brief Makes a quaternion from 4 floats.
*/
Quaternion::Quaternion(f32 h, f32 i, f32 j, f32 k) {
    this->h = h;
    this->i = i;
    this->j = j;
    this->k = k;
}

/**
 * @brief Makes a euler quaternion from a Vec3.
 * 
 * @param euler Must in the ijk format.
*/
Quaternion::Quaternion(Vec3& euler) {
    float si = sin(euler.x() / 2);
	float sj = sin(euler.y() / 2);
	float sk = sin(euler.z() / 2);

	float ci = cos(euler.x() / 2);
	float cj = cos(euler.y() / 2);
    float ck = cos(euler.z() / 2);

    h =  sj * si * sk + cj * ci * ck;
	i =  cj * si * ck + sj * ci * sk;
	j = -cj * si * sk + sj * ci * ck;
	k = -sj * si * ck + cj * ci * sk;
}

/**
 * @brief Makes a normalized axis quaternion from a Vec3 and angle.
 * 
 * @param axis Must in the ijk format.
 * @param angle Must be in degrees.
*/
Quaternion::Quaternion(Vec3& axis, float angle) {
    f32 sinAngle = sin(angle / 2);
    i = axis.x() * sinAngle;
    j = axis.y() * sinAngle;
    k = axis.z() * sinAngle;
    h = cos(angle / 2);
    normalize(*this);
}

/**
 * @brief Deconstructor.
*/
Quaternion::~Quaternion() {}

/**
 * @brief A static return from the identity constructor.
*/
Quaternion Quaternion::identity() {
    return Quaternion();
}

/**
 * @brief A static return from the euler constructor.
 * 
 * @param euler Must in the ijk format.
*/
Quaternion Quaternion::euler(Vec3& euler) {
    return Quaternion(euler);
}

/**
 * @brief Normalizes this quaternion.
 * 
 * @returns This quaternion.
*/
Quaternion Quaternion::normalize() {
    f32 mag = magnitude();
    
    if(abs(mag - 1) < 0.001)
        return *this;
    
    h /= mag;
    i /= mag;
    j /= mag;
    k /= mag;

    return *this;
}

/**
 * @brief Normalizes this quaternion and stores it in the param quaternion.
 * 
 * @param q Quaternion to be stored in.
 *
 * @returns This quaternion.
*/
Quaternion Quaternion::normalize(Quaternion& q) {
    f32 mag = magnitude();
    
    if(abs(mag - 1) < 0.001)
        return *this;
    
    q.h = h / mag;
    q.i = i / mag;
    q.j = j / mag;
    q.k = k / mag;

    return *this;
}

/**
 * @brief Inverses this quaternion.
 * 
 * @returns This quaternion.
*/
Quaternion Quaternion::inverse() {
    h = -h;

    return *this;
}

/**
 * @brief Inverses this quaternion and stores it in the param quaternion.
 * 
 * @param q Quaternion to be stored in.
 * 
 * @returns This quaternion.
*/
Quaternion Quaternion::inverse(Quaternion* q) {
    q->h = -h;
    q->i =  i;
    q->j =  j;
    q->k =  k;

    return *this;
}

/**
 * @brief Inverts the imaginary numbers.
 * 
 * @returns This quaternion.
*/
Quaternion Quaternion::conjugate() {
    i = -i;
    j = -j;
    k = -k;

    return *this;
}

/**
 * @brief Calculates the magnitude from this quaternion.
 * 
 * @returns The answer of the magnitude.
*/
f32 Quaternion::magnitude() {
    return sqrt(h * h + i * i + j * j + k * k);
}

/**
 * @brief Multiplies the quaternion with a scale.
 * 
 * @param scale the number to be multiplied.
 * 
 * @returns A new quaternion that is multiplied. 
*/
Quaternion Quaternion::operator*(f32 scale) {
    return Quaternion(h * scale, i * scale, j * scale, k * scale);
}

/**
 * @brief Multiplies the param quaternion with this quaternion.
 * 
 * @param q The quaternion to be multiplied with.
 * 
 * @returns The new multiplied quaternion.
*/
Quaternion Quaternion::operator*(Quaternion& q) {
    return Quaternion(
        -i * q.i - j * q.j - k * q.k + h * q.h,
         i * q.h + j * q.k - k * q.j + h * q.i,
		-i * q.k + j * q.h + k * q.i + h * q.j,
		 i * q.j - j * q.i + k * q.h + h * q.k
    );
}

/**
 * @brief Multiplies the quaternion with a scale.
 * 
 * @param scale the number to be multiplied.
*/
void Quaternion::operator*=(f32 scale) {
    h *= scale;
    i *= scale;
    j *= scale;
    k *= scale;
}

/**
 * @brief Multiplies the param quaternion with this quaternion.
 * 
 * @param q The quaternion to be multiplied with.
*/
void Quaternion::operator*=(Quaternion& q) {
    h = -i * q.i - j * q.j - k * q.k + h * q.h;
    i =  i * q.h + j * q.k - k * q.j + h * q.i;
    j = -i * q.k + j * q.h + k * q.i + h * q.j;
    k =  i * q.j - j * q.i + k * q.h + h * q.k;
}

/**
 * @brief Addes the param quaternion with this quaternion.
 * 
 * @param q The quaternion to be added with.
 * 
 * @returns The new added quaternion.
*/
Quaternion Quaternion::operator+(Quaternion& q) {
    return Quaternion(h + q.h, i + q.i, j + q.j, k + q.k);
}

/**
 * @brief Subtractes the param quaternion with this quaternion.
 * 
 * @param q The quaternion to be subtracted with.
 * 
 * @returns The new subtracted quaternion.
*/
Quaternion Quaternion::operator-(Quaternion& q) {
    return Quaternion(h - q.h, i - q.i, j - q.j, k - q.k);
}

/**
 * @brief Copies this quaternion and returns a new one.
*/
Quaternion Quaternion::copy() {
    return Quaternion(h,i,j,k);
}

} // namespace Lila