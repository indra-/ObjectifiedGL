#include "Math/Matrix4.h"

namespace OGL
{
	Matrix4::Matrix4()
	{
		*this = Matrix4(1,0,0,0,
						0,1,0,0,
						0,0,1,0,
						0,0,0,1);
	}

	Matrix4::Matrix4(float a00, float a01, float a02, float a03, 
					 float a10, float a11, float a12, float a13, 
					 float a20, float a21, float a22, float a23,
					 float a30, float a31, float a32, float a33)
	{
		data[0][0]=a00; data[0][1]=a01; data[0][2]=a02; data[0][3]=a03;
		data[1][0]=a10; data[1][1]=a11; data[1][2]=a12; data[1][3]=a13;
		data[2][0]=a20; data[2][1]=a21; data[2][2]=a22; data[2][3]=a23;
		data[3][0]=a30; data[3][1]=a31; data[3][2]=a32; data[3][3]=a33;
	}

	Matrix4::Matrix4(const Matrix4& other)
	{
		*this = other;
	}

	Matrix4& Matrix4::operator=(const Matrix4& other)
	{
		if(&other == this) return *this;

		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	}
}