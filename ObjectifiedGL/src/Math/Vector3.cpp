#include "Math\Vector3.h"
#include <math.h>

namespace OGL {

	Vector3::Vector3() : x(0), y(0), z(0) { }

	Vector3::Vector3( float x, float y, float z) : x(x), y(y), z(z) { }

	Vector3::Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z) { }

	Vector3& Vector3::operator=(const Vector3& other)
	{
		if(this == &other) return *this;
		
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	const Vector3 Vector3::operator+(const Vector3 &vec) const
	{
		return Vector3(x+vec.x, y+vec.y, z+vec.z);
	}

	const Vector3 Vector3::operator-(const Vector3 &vec) const
	{
		return Vector3(x-vec.x, y-vec.y, z-vec.z);
	}

	const Vector3 operator*(const Vector3 &lhs, const float &rhs)
	{
		return Vector3(lhs.x*rhs, lhs.y*rhs, lhs.z*rhs);
	}

	const Vector3 operator*(const float &lhs, const Vector3 &rhs) 
	{
		return rhs * lhs;
	}

	const Vector3 operator/(const Vector3 &lhs, const float &rhs)
	{
		return lhs * (1/rhs);
	}

	const Vector3 operator/(const float &lhs, const Vector3 &rhs)
	{
		return rhs / lhs;
	}

	float Vector3::magnitude() const
	{
		return sqrt( x*x + y*y + z*z );
	}

	float Vector3::sqrMagnitude() const
	{
		return x*x + y*y + z*z;
	}

	Vector3 Vector3::normalized() const
	{
		// p_normalized = p / |p|
		float length = magnitude();
		return Vector3(x/length, y/length, z/length);
	}

	float Vector3::Dot(const Vector3 &vec1, const Vector3 &vec2)
	{
		return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
	}

	float Vector3::Distance(const Vector3 &vec1, const Vector3 &vec2)
	{
		// |p-q| = sqrt( (p-q) * (p-q) )
		return sqrt( Vector3::Dot(vec1-vec2, vec1-vec2) );
	}
}