#include "Math\Vector3.h"
#include "UnitTest++.h"
#include <math.h>
#include <iostream>

using namespace OGL;

SUITE(Vector3_tests)
{

	struct Vector3Fixture
	{

		Vector3 vector1;
		Vector3 vector2;

		float x;
		float x´;
		float y;
		float y´;
		float z;
		float z´;

		Vector3Fixture() 
		{ 
			x = 2;
			x´ = 7;
			y = 4;
			y´ = 9;
			z = 3;
			z´ = 8;
			vector1 = Vector3(x,y,z);
			vector2 = Vector3(x´,y´,z´);
		}
		~Vector3Fixture() { }

	};

	TEST(DefaultConstructorTest)
	{
		Vector3 vec;
		CHECK_EQUAL(0, vec.x);
		CHECK_EQUAL(0, vec.y);
		CHECK_EQUAL(0, vec.z);
	}

	TEST(ConstructorTest)
	{
		Vector3 vec(2,5,4);
		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(5, vec.y);
		CHECK_EQUAL(4, vec.z);
	}

	TEST(CopyConstructorTest)
	{
		Vector3 vec1(2,5,4);
		Vector3 vec2(vec1);

		CHECK_EQUAL(2, vec2.x);
		CHECK_EQUAL(5, vec2.y);
		CHECK_EQUAL(4, vec2.z);
	}

	TEST(CopyAssignmentOperator)
	{
		Vector3 vec1(2,5,4);
		Vector3 vec2(3,8,9);

		vec1 = vec2;

		CHECK_EQUAL(3, vec1.x);
		CHECK_EQUAL(8, vec1.y);
		CHECK_EQUAL(9, vec1.z);

		CHECK(&vec1 != &vec2);

		Vector3 vec = Vector3(2,4,3);

		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(4, vec.y);
		CHECK_EQUAL(3, vec.z);
	}

	TEST_FIXTURE(Vector3Fixture, MagnitudeTest)
	{

		float sum = x*x + y*y + z*z;

		float sumSqrt = sqrt(sum);

		CHECK_EQUAL(sumSqrt, vector1.magnitude());
		CHECK(vector2.magnitude() > vector1.magnitude());
	}

	TEST_FIXTURE(Vector3Fixture, SquaredMagnitudeTest)
	{

		float sum = x*x + y*y + z*z;

		CHECK_EQUAL(sum, vector1.sqrMagnitude());

		CHECK(vector2.sqrMagnitude() > vector1.sqrMagnitude());
	}

	TEST_FIXTURE(Vector3Fixture, AdditionTest)
	{
		
		Vector3 vec(9,13,11);
		Vector3 temp = vector1 + vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
		CHECK_EQUAL(vec.z, temp.z);
	}

	TEST_FIXTURE(Vector3Fixture, DifferenceTest)
	{
		Vector3 vec(-5,-5,-5);
		Vector3 temp = vector1 - vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
		CHECK_EQUAL(vec.z, temp.z);
	}

	TEST_FIXTURE(Vector3Fixture, DotProductTest)
	{	

		float dot_temp = x*x´ + y*y´ + z*z´;

		float dot_product = Vector3::Dot(vector1, vector2);

		CHECK_EQUAL(dot_temp, dot_product);
	}

	TEST_FIXTURE(Vector3Fixture, MultiplicationTest)
	{
		Vector3 temp = vector1 * 2;

		CHECK_EQUAL(temp.x, 4);
		CHECK_EQUAL(temp.y, 8);
		CHECK_EQUAL(temp.z, 6);

		temp = 2 * vector2;

		CHECK_EQUAL(temp.x, 14);
		CHECK_EQUAL(temp.y, 18);
		CHECK_EQUAL(temp.z, 16);

	}

	TEST_FIXTURE(Vector3Fixture, DivisionTest)
	{
		vector1 = Vector3(2,4,3);

		Vector3 temp = vector1 / 2;

		CHECK_EQUAL(temp.x, 1.0f);
		CHECK_EQUAL(temp.y, 2.0f);
		CHECK_EQUAL(temp.z, 1.5f);

		temp = 2 / vector2;

		CHECK_EQUAL(temp.x, 3.5f);
		CHECK_EQUAL(temp.y, 4.5f);
		CHECK_EQUAL(temp.z, 4.0f);

	}

	TEST_FIXTURE(Vector3Fixture, NormalizationTest)
	{
		float sum = x*x + y*y + z*z;

		float sumSqrt = sqrt(sum);

		float n_x = x/sumSqrt;
		float n_y = y/sumSqrt;
		float n_z = z/sumSqrt;

		Vector3 temp = vector1.normalized();

		CHECK_EQUAL(temp.x, n_x);
		CHECK_EQUAL(temp.y, n_y);
		CHECK_EQUAL(temp.z, n_z);
	}

	TEST_FIXTURE(Vector3Fixture, DistanceTest)
	{
		float x = -5;
		float y = -5;
		float z = -5;
		float dot = x*x + y*y + z*z; // (vector1 - vector2) * (vector1 - vector2)
		float dotSqrt = sqrt(dot); // sqrt( (vector1 - vector2) * (vector1 - vector2)) = |vector1 - vector2|

		float distance = Vector3::Distance(vector1, vector2);

		CHECK_EQUAL(dotSqrt, distance);
	}

	TEST_FIXTURE(Vector3Fixture, CrossProductTest)
	{
		Vector3 temp = Vector3::Cross(vector1, vector2);

		CHECK_EQUAL(temp.x, 5);
		CHECK_EQUAL(temp.y, 5);
		CHECK_EQUAL(temp.z, -10);

		// Angle between the cross product and given vectors should be 90deg (cosine 0) in both cases.

		float dotProduct = Vector3::Dot(vector1, temp);
		float denominator = vector1.magnitude() * temp.magnitude();

		float cosine = dotProduct / denominator;
		
		CHECK_EQUAL(cosine, 0);

		dotProduct = Vector3::Dot(vector2, temp);
		denominator = vector2.magnitude() * temp.magnitude();

		cosine = dotProduct / denominator;

		CHECK_EQUAL(cosine, 0);
	}
}