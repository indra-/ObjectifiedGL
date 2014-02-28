#include "Math/Matrix4.h"
#include "UnitTest++.h"
#include <math.h>
using namespace OGL;

SUITE(Matrix4_tests)
{

	struct Matrix4Fixture
	{

		Matrix4 mat;

		Matrix4Fixture() 
		{ 
		}
		~Matrix4Fixture() { }

	};

	TEST(DefaultConstructorTest)
	{
		Matrix4 mat;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				if(i==j)
				{
					CHECK_EQUAL(1,mat.m_data[i][j]);
				} else {
					CHECK_EQUAL(0,mat.m_data[i][j]);
				}
			}
		}
	}

	TEST(ConstructorTest)
	{
		float test1[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
		Matrix4 mat1(test1);
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(test1[i][j], mat1.m_data[i][j]);
			}
		}
		float test2[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
		Matrix4 mat2(test2);
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(test1[i][j], mat2.m_data[i][j]);
			}
		}
		Matrix4 mat3(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(test1[i][j], mat3.m_data[i][j]);
			}
		}
	}

	TEST(CopyConstructorTest)
	{
		Matrix4 mat1(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
		Matrix4 mat2(mat1);
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(i*4+j+1, mat2.m_data[i][j]);
			}
		}
	}

	TEST(AssignmentOperator)
	{
		Matrix4 mat1(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
		Matrix4 mat2;
		mat2 = mat1;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(i*4+j+1, mat2.m_data[i][j]);
			}
		}
		Matrix4 mat3(16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1);
		mat1 = mat3;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				CHECK_EQUAL(i*4+j+1, mat2.m_data[i][j]); // check that mat2 has not changed
			}
		}
	}
}