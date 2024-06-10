#pragma once

#include "Platform/Defines.h"

#include "Vectors.h"

namespace Lila {

	class Quaternion {
	public:
		Quaternion();
		Quaternion(Vec4& vec);
		Quaternion(f32 h, f32 i, f32 j, f32 k);

		Quaternion(Vec3& euler);
		Quaternion(Vec3& axis, float angle);

		~Quaternion();

		// Returns a standard quaternion.
		static Quaternion identity();

		// Creates a quaternion from an euler rotation.
		static Quaternion euler(Vec3& euler);

		Quaternion normalize();
		Quaternion normalize(Quaternion& q);

		Quaternion inverse();
		Quaternion inverse(Quaternion* q);

		Quaternion conjugate();

		f32 magnitude();

		Quaternion operator*(f32 scale);
		Quaternion operator*(Quaternion& q);

		void operator*=(f32 scale);
		void operator*=(Quaternion& q);

		Quaternion operator+(Quaternion& q);
		Quaternion operator-(Quaternion& q);

		Quaternion copy();

	private:
		// A Quaternion is defined by 1 real number (h = 1) and 3 imaginary numbers (i = j = k = 0).
		f32 h,i,j,k;
	};

} // namespace Lila