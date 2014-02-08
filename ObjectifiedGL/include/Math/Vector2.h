#pragma once

#ifndef VEC2_H
#define VEC2_H

namespace OGL {

	class Vector2
	{
	public:

		float x, y;

		Vector2();

		Vector2( float x, float y);

		Vector2(const Vector2 &other);

		Vector2& operator=(const Vector2& other);

		const Vector2 operator+(const Vector2 &vec) const; 

		const Vector2 operator-(const Vector2 &vec) const;

		const Vector2 friend operator*(const Vector2 &lhs, const float &rhs);

		const Vector2 friend operator*(const float &lhs, const Vector2 &rhs);

		const Vector2 friend operator/(const Vector2 &lhs, const float &rhs);

		const Vector2 friend operator/(const float &lhs, const Vector2 &rhs);

		static float Dot(const Vector2 &vec1, const Vector2 &vec2);

		static float Distance(const Vector2 &vec1, const Vector2 &vec2);

		float magnitude() const;

		float sqrMagnitude() const;

		Vector2 normalized() const;

		virtual ~Vector2() { }

	};
}

#endif