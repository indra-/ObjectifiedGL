#include "Math/Vector2.h"
#include <math.h>

namespace OGL {

	Vector2::Vector2() : x(0), y(0){ }

	Vector2::Vector2( float x, float y) : x(x), y(y) { }

	Vector2::Vector2(const Vector2 &other) : x(other.x), y(other.y) { }

	Vector2& Vector2::operator=(const Vector2& other)
	{
		if(this == &other) return *this;
		
		x = other.x;
		y = other.y;

		return *this;
	}

	const Vector2 Vector2::operator+(const Vector2 &vec) const
	{
		return Vector2(x+vec.x, y+vec.y);
	}

	const Vector2 Vector2::operator-(const Vector2 &vec) const
	{
		return Vector2(x-vec.x, y-vec.y);
	}

	const Vector2 operator*(const Vector2 &lhs, const float &rhs)
	{
		return Vector2(lhs.x*rhs, lhs.y*rhs);
	}

	const Vector2 operator*(const float &lhs, const Vector2 &rhs) 
	{
		return rhs * lhs;
	}

	const Vector2 operator/(const Vector2 &lhs, const float &rhs)
	{
		return lhs * (1/rhs);
	}

	const Vector2 operator/(const float &lhs, const Vector2 &rhs)
	{
		return rhs / lhs;
	}

	float Vector2::magnitude() const
	{
		return sqrt( x*x + y*y );
	}

	float Vector2::sqrMagnitude() const
	{
		return x*x + y*y;
	}

	Vector2 Vector2::normalized() const
	{
		// p_normalized = p / |p|
		float length = magnitude();
		return Vector2(x/length, y/length);
	}

	float Vector2::Dot(const Vector2 &vec1, const Vector2 &vec2)
	{
		return vec1.x*vec2.x + vec1.y*vec2.y;
	}

	float Vector2::Distance(const Vector2 &vec1, const Vector2 &vec2)
	{
		// |p-q| = sqrt( (p-q) * (p-q) )
		return sqrt( Vector2::Dot(vec1-vec2, vec1-vec2) );
	}
}