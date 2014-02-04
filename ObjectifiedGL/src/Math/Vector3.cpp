#include "Math\Vector3.h"
#include <math.h>

namespace OGL {

	Vector3::Vector3( float x = 0.0f, float y =  0.0f, float z = 0.0f) : x(x), y(y), z(z) { }

	Vector3::Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z) { }

	Vector3& Vector3::operator=(const Vector3& other)
	{
		if(this == &other) return *this;
		
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

		return *this;
	}

	float Vector3::magnitude()
	{
		return sqrt( x*x + y*y + z*z );
	}

	float Vector3::sqrMagnitude()
	{
		return x*x + y*y + z*z;
	}

	const Vector3 Vector3::operator+(const Vector3 vec) const
	{
		return Vector3(this->x+x, this->y+y, this->z+z);
	}

	const Vector3 Vector3::operator-(const Vector3 vec) const
	{
		return Vector3(this->x-x, this->y-y, this->z-z);
	}

}