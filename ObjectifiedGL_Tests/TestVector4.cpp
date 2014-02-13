#include "Math\Vector4.h"
#include "UnitTest++.h"
#include <math.h>
#include <iostream>

using namespace OGL;

SUITE(Vector4_tests)
{

	struct Vector4Fixture
	{

		Vector4 vector1;
		Vector4 vector2;

		float x;
		float x´;
		float y;
		float y´;
		float z;
		float z´;
		float w;
		float w´;

		Vector4Fixture() 
		{ 
			x = 2;
			x´ = 7;
			y = 4;
			y´ = 9;
			z = 3;
			z´ = 8;
			w = 2;
			w´ = 7;
			vector1 = Vector4(x,y,z,w);
			vector2 = Vector4(x´,y´,z´,w´);
		}
		~Vector4Fixture() { }

	};

	TEST(DefaultConstructorTest)
	{
		Vector4 vec;
		CHECK_EQUAL(0, vec.x);
		CHECK_EQUAL(0, vec.y);
		CHECK_EQUAL(0, vec.z);
		CHECK_EQUAL(0, vec.w);
	}

	TEST(ConstructorTest)
	{
		Vector4 vec(2,5,4,3);
		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(5, vec.y);
		CHECK_EQUAL(4, vec.z);
		CHECK_EQUAL(3, vec.w);
	}

	TEST(CopyConstructorTest)
	{
		Vector4 vec1(2,5,4,3);
		Vector4 vec2(vec1);

		CHECK_EQUAL(2, vec2.x);
		CHECK_EQUAL(5, vec2.y);
		CHECK_EQUAL(4, vec2.z);
		CHECK_EQUAL(3, vec2.w);
	}

	TEST(CopyAssignmentOperator)
	{
		Vector4 vec1(2,5,4,3);
		Vector4 vec2(3,8,9,7);

		vec1 = vec2;

		CHECK_EQUAL(3, vec1.x);
		CHECK_EQUAL(8, vec1.y);
		CHECK_EQUAL(9, vec1.z);
		CHECK_EQUAL(7, vec1.w);

		CHECK(&vec1 != &vec2);

		Vector4 vec = Vector4(2,4,3,5);

		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(4, vec.y);
		CHECK_EQUAL(3, vec.z);
		CHECK_EQUAL(5, vec.w);
	}

	TEST_FIXTURE(Vector4Fixture, MagnitudeTest)
	{

		float sum = x*x + y*y + z*z + w*w;

		float sumSqrt = sqrt(sum);

		CHECK_EQUAL(sumSqrt, vector1.magnitude());
		CHECK(vector2.magnitude() > vector1.magnitude());
	}

	TEST_FIXTURE(Vector4Fixture, SquaredMagnitudeTest)
	{

		float sum = x*x + y*y + z*z + w*w;

		CHECK_EQUAL(sum, vector1.sqrMagnitude());

		CHECK(vector2.sqrMagnitude() > vector1.sqrMagnitude());
	}

	TEST_FIXTURE(Vector4Fixture, AdditionTest)
	{
		
		Vector4 vec(9,13,11,9);
		Vector4 temp = vector1 + vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
		CHECK_EQUAL(vec.z, temp.z);
		CHECK_EQUAL(vec.w, temp.w);
	}

	TEST_FIXTURE(Vector4Fixture, DifferenceTest)
	{
		Vector4 vec(-5,-5,-5,-5);
		Vector4 temp = vector1 - vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
		CHECK_EQUAL(vec.z, temp.z);
		CHECK_EQUAL(vec.w, temp.w);
	}

	TEST_FIXTURE(Vector4Fixture, DotProductTest)
	{	

		float dot_temp = x*x´ + y*y´ + z*z´ + w*w´;

		float dot_product = Vector4::Dot(vector1, vector2);

		CHECK_EQUAL(dot_temp, dot_product);
	}

	TEST_FIXTURE(Vector4Fixture, MultiplicationTest)
	{
		Vector4 temp = vector1 * 2;

		CHECK_EQUAL(temp.x, 4);
		CHECK_EQUAL(temp.y, 8);
		CHECK_EQUAL(temp.z, 6);
		CHECK_EQUAL(temp.w, 4);

		temp = 2 * vector2;

		CHECK_EQUAL(temp.x, 14);
		CHECK_EQUAL(temp.y, 18);
		CHECK_EQUAL(temp.z, 16);
		CHECK_EQUAL(temp.w, 14);

	}

	TEST_FIXTURE(Vector4Fixture, DivisionTest)
	{
		vector1 = Vector4(2,4,3,6);

		Vector4 temp = vector1 / 2;

		CHECK_EQUAL(temp.x, 1.0f);
		CHECK_EQUAL(temp.y, 2.0f);
		CHECK_EQUAL(temp.z, 1.5f);
		CHECK_EQUAL(temp.w, 3.0f);

		temp = 2 / vector2;

		CHECK_EQUAL(temp.x, 3.5f);
		CHECK_EQUAL(temp.y, 4.5f);
		CHECK_EQUAL(temp.z, 4.0f);
		CHECK_EQUAL(temp.w, 3.5f);

	}

	TEST_FIXTURE(Vector4Fixture, NormalizationTest)
	{
		float sum = x*x + y*y + z*z + w*w;

		float sumSqrt = sqrt(sum);

		float n_x = x/sumSqrt;
		float n_y = y/sumSqrt;
		float n_z = z/sumSqrt;
		float n_w = w/sumSqrt;

		Vector4 temp = vector1.normalized();

		CHECK_EQUAL(temp.x, n_x);
		CHECK_EQUAL(temp.y, n_y);
		CHECK_EQUAL(temp.z, n_z);
		CHECK_EQUAL(temp.w, n_w);
	}

	TEST_FIXTURE(Vector4Fixture, DistanceTest)
	{
		float x = -5;
		float y = -5;
		float z = -5;
		float w = -5;
		float dot = x*x + y*y + z*z + w*w; // (vector1 - vector2) * (vector1 - vector2)
		float dotSqrt = sqrt(dot); // sqrt( (vector1 - vector2) * (vector1 - vector2)) = |vector1 - vector2|

		float distance = Vector4::Distance(vector1, vector2);

		CHECK_EQUAL(dotSqrt, distance);
	}
}