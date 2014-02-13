#include "Math\Vector4.h"
#include <math.h>

namespace OGL {

	Vector4::Vector4() : x(0), y(0), z(0), w(0) { }

	Vector4::Vector4( float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

	Vector4::Vector4(const Vector4 &other) : x(other.x), y(other.y), z(other.z), w(other.w) { }

	Vector4& Vector4::operator=(const Vector4& other)
	{
		if(this == &other) return *this;
		
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;

		return *this;
	}

	const Vector4 Vector4::operator+(const Vector4 &vec) const
	{
		return Vector4(x+vec.x, y+vec.y, z+vec.z, w+vec.w);
	}

	const Vector4 Vector4::operator-(const Vector4 &vec) const
	{
		return Vector4(x-vec.x, y-vec.y, z-vec.z, w-vec.w);
	}

	const Vector4 operator*(const Vector4 &lhs, const float &rhs)
	{
		return Vector4(lhs.x*rhs, lhs.y*rhs, lhs.z*rhs, lhs.w*rhs);
	}

	const Vector4 operator*(const float &lhs, const Vector4 &rhs) 
	{
		return rhs * lhs;
	}

	const Vector4 operator/(const Vector4 &lhs, const float &rhs)
	{
		return lhs * (1/rhs);
	}

	const Vector4 operator/(const float &lhs, const Vector4 &rhs)
	{
		return rhs / lhs;
	}

	float Vector4::magnitude() const
	{
		return sqrt( x*x + y*y + z*z + w*w);
	}

	float Vector4::sqrMagnitude() const
	{
		return x*x + y*y + z*z + w*w;
	}

	Vector4 Vector4::normalized() const
	{
		// p_normalized = p / |p|
		float length = magnitude();
		return Vector4(x/length, y/length, z/length, w/length);
	}

	float Vector4::Dot(const Vector4 &vec1, const Vector4 &vec2)
	{
		return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z + vec1.w * vec2.w;
	}

	float Vector4::Distance(const Vector4 &vec1, const Vector4 &vec2)
	{
		// |p-q| = sqrt( (p-q) * (p-q) )
		return sqrt( Vector4::Dot(vec1-vec2, vec1-vec2) );
	}
}