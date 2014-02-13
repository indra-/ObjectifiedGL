#pragma once

#ifndef VEC4_H
#define VEC4_H

namespace OGL {

	class Vector4
	{
	public:

		float x, y, z, w;

		Vector4();

		Vector4( float x, float y, float z, float w);

		Vector4(const Vector4 &other);

		Vector4& operator=(const Vector4& other);

		const Vector4 operator+(const Vector4 &vec) const; 

		const Vector4 operator-(const Vector4 &vec) const;

		const Vector4 friend operator*(const Vector4 &lhs, const float &rhs);

		const Vector4 friend operator*(const float &lhs, const Vector4 &rhs);

		const Vector4 friend operator/(const Vector4 &lhs, const float &rhs);

		const Vector4 friend operator/(const float &lhs, const Vector4 &rhs);

		static float Dot(const Vector4 &vec1, const Vector4 &vec2);

		static Vector4 Cross(const Vector4 &vec1, const Vector4 &vec2);

		static float Distance(const Vector4 &vec1, const Vector4 &vec2);

		float magnitude() const;

		float sqrMagnitude() const;

		Vector4 normalized() const;

		virtual ~Vector4() { }

	};
}

#endif