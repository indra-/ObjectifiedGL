#include "Math\Vector2.h"
#include "UnitTest++.h"
#include <math.h>
#include <iostream>

using namespace OGL;

SUITE(Vector2_tests)
{

	struct Vector2Fixture
	{

		Vector2 vector1;
		Vector2 vector2;

		float x;
		float x´;
		float y;
		float y´;

		Vector2Fixture() 
		{ 
			x = 2;
			x´ = 7;
			y = 4;
			y´ = 9;
			vector1 = Vector2(x,y);
			vector2 = Vector2(x´,y´);
		}
		~Vector2Fixture() { }

	};

	TEST(DefaultConstructorTest)
	{
		Vector2 vec;
		CHECK_EQUAL(0, vec.x);
		CHECK_EQUAL(0, vec.y);
	}

	TEST(ConstructorTest)
	{
		Vector2 vec(2,5);
		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(5, vec.y);
	}

	TEST(CopyConstructorTest)
	{
		Vector2 vec1(2,5);
		Vector2 vec2(vec1);

		CHECK_EQUAL(2, vec2.x);
		CHECK_EQUAL(5, vec2.y);
	}

	TEST(CopyAssignmentOperator)
	{
		Vector2 vec1(2,5);
		Vector2 vec2(3,8);

		vec1 = vec2;

		CHECK_EQUAL(3, vec1.x);
		CHECK_EQUAL(8, vec1.y);

		CHECK(&vec1 != &vec2);

		Vector2 vec = Vector2(2,4);

		CHECK_EQUAL(2, vec.x);
		CHECK_EQUAL(4, vec.y);
	}

	TEST_FIXTURE(Vector2Fixture, MagnitudeTest)
	{

		float sum = x*x + y*y;

		float sumSqrt = sqrt(sum);

		CHECK_EQUAL(sumSqrt, vector1.magnitude());
		CHECK(vector2.magnitude() > vector1.magnitude());
	}

	TEST_FIXTURE(Vector2Fixture, SquaredMagnitudeTest)
	{

		float sum = x*x + y*y;

		CHECK_EQUAL(sum, vector1.sqrMagnitude());

		CHECK(vector2.sqrMagnitude() > vector1.sqrMagnitude());
	}

	TEST_FIXTURE(Vector2Fixture, AdditionTest)
	{
		
		Vector2 vec(9,13);
		Vector2 temp = vector1 + vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
	}

	TEST_FIXTURE(Vector2Fixture, DifferenceTest)
	{
		Vector2 vec(-5,-5);
		Vector2 temp = vector1 - vector2;

		CHECK_EQUAL(vec.x, temp.x);
		CHECK_EQUAL(vec.y, temp.y);
	}

	TEST_FIXTURE(Vector2Fixture, DotProductTest)
	{	

		float dot_temp = x*x´ + y*y´;

		float dot_product = Vector2::Dot(vector1, vector2);

		CHECK_EQUAL(dot_temp, dot_product);
	}

	TEST_FIXTURE(Vector2Fixture, MultiplicationTest)
	{
		Vector2 temp = vector1 * 2;

		CHECK_EQUAL(temp.x, 4);
		CHECK_EQUAL(temp.y, 8);

		temp = 2 * vector2;

		CHECK_EQUAL(temp.x, 14);
		CHECK_EQUAL(temp.y, 18);

	}

	TEST_FIXTURE(Vector2Fixture, DivisionTest)
	{
		vector1 = Vector2(2,4);

		Vector2 temp = vector1 / 2;

		CHECK_EQUAL(temp.x, 1.0f);
		CHECK_EQUAL(temp.y, 2.0f);

		temp = 2 / vector2;

		CHECK_EQUAL(temp.x, 3.5f);
		CHECK_EQUAL(temp.y, 4.5f);

	}

	TEST_FIXTURE(Vector2Fixture, NormalizationTest)
	{
		float sum = x*x + y*y;

		float sumSqrt = sqrt(sum);

		float n_x = x/sumSqrt;
		float n_y = y/sumSqrt;

		Vector2 temp = vector1.normalized();

		CHECK_EQUAL(temp.x, n_x);
		CHECK_EQUAL(temp.y, n_y);
	}

	TEST_FIXTURE(Vector2Fixture, DistanceTest)
	{
		float x = -5;
		float y = -5;
		float dot = x*x + y*y; // (vector1 - vector2) * (vector1 - vector2)
		float dotSqrt = sqrt(dot); // sqrt( (vector1 - vector2) * (vector1 - vector2)) = |vector1 - vector2|

		float distance = Vector2::Distance(vector1, vector2);

		CHECK_EQUAL(dotSqrt, distance);
	}
}