#pragma once

#ifndef VEC3_H
#define VEC3_H

namespace OGL {

	class Vector3
	{
	public:

		float x, y, z;

		Vector3();

		Vector3( float x, float y, float z);

		Vector3(const Vector3 &other);

		Vector3& operator=(const Vector3& other);

		const Vector3 operator+(const Vector3 &vec) const; 
		const Vector3 operator-(const Vector3 &vec) const;
		const Vector3 friend operator*(const Vector3 &lhs, const float &rhs);
		const Vector3 friend operator*(const float &lhs, const Vector3 &rhs);
		const Vector3 friend operator/(const Vector3 &lhs, const float &rhs);
		const Vector3 friend operator/(const float &lhs, const Vector3 &rhs);

		static float Dot(const Vector3 &vec1, const Vector3 &vec2);
		static Vector3 Cross(const Vector3 &vec1, const Vector3 &vec2);
		static float Distance(const Vector3 &vec1, const Vector3 &vec2);

		float magnitude() const;
		float sqrMagnitude() const;
		Vector3 normalized() const;

		virtual ~Vector3() { }

	};
}

#endif