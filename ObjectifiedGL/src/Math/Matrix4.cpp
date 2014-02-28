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
	Matrix4::Matrix4(const float mat[16])
	 {
		 for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				m_data[i][j] = mat[i*4 + j];
			}
		}
	 };

	 Matrix4::Matrix4(const float mat[4][4])
	 {
		 for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				m_data[i][j] = mat[i][j];
			}
		}
	 };

	Matrix4::Matrix4(float a00, float a01, float a02, float a03, 
					 float a10, float a11, float a12, float a13, 
					 float a20, float a21, float a22, float a23,
					 float a30, float a31, float a32, float a33)
	{
		m_data[0][0]=a00; m_data[0][1]=a01; m_data[0][2]=a02; m_data[0][3]=a03;
		m_data[1][0]=a10; m_data[1][1]=a11; m_data[1][2]=a12; m_data[1][3]=a13;
		m_data[2][0]=a20; m_data[2][1]=a21; m_data[2][2]=a22; m_data[2][3]=a23;
		m_data[3][0]=a30; m_data[3][1]=a31; m_data[3][2]=a32; m_data[3][3]=a33;
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
				m_data[i][j] = other.m_data[i][j];
			}
		}
		return *this;
	}
}