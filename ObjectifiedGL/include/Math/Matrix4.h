#pragma once

#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector3.h"
#include "Vector4.h"

namespace OGL {

	class Matrix4 
	{
		public:
			
			Matrix4();												// Creates an identity matrix
			Matrix4(float a00, float a01, float a02, float a03,		// Row-major order
					float a10, float a11, float a12, float a13, 
					float a20, float a21, float a22, float a23,
					float a30, float a31, float a32, float a33);
			Matrix4(const Matrix4& other);
			virtual ~Matrix4() {};
	
			Matrix4& operator=(const Matrix4& other);
			const Matrix4 operator*(const Matrix4& other) const;
			const Matrix4 operator*(const Vector3& other) const;
			const Matrix4 operator*(const Vector4& other) const;

			Matrix4& rotate(const Vector4& axis, float angleDeg);
			Matrix4& rotateX(float angleDeg);
			Matrix4& rotateY(float angleDeg);
			Matrix4& rotateZ(float angleDeg);

			Matrix4& translate(const Vector3& vec);
			Matrix4& scale(const Vector3& vec);

			Matrix4 inverse() const;
			Matrix4 transpose() const;
			Matrix4 determinant() const;

			private: 
				float data[4][4];
	};
}

#endif