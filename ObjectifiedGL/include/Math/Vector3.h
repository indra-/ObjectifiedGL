#pragma once

#ifndef VEC3_H
#define VEC3_H

namespace OGL {

	class Vector3
	{
	public:

		float x, y, z;

		Vector3( float x, float y, float z);

		Vector3(const Vector3 &other);

		Vector3& operator=(const Vector3& other);

		float magnitude();

		float sqrMagnitude();

		const Vector3 operator+(const Vector3 vec) const; 

		const Vector3 operator-(const Vector3 vec) const;

		const Vector3 friend operator*(const Vector3 lhs, float rhs);

		const Vector3 friend operator*(float lhs, const Vector3 rhs);

		const Vector3 friend operator/(const Vector3 lhs, float rhs);

		const Vector3 friend operator/(float lhs, const Vector3 rhs);

		static Vector3 Dot(const Vector3 vec1, const Vector3 vec2);

		virtual ~Vector3() { }

	};
}

#endif