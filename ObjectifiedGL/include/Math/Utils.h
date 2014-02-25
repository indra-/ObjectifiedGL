#pragma once

#ifndef HELPERS_H
#define HELPERS_H

#include "Vector4.h"
#include "Matrix4.h"

namespace OGL
{
	class Helpers
	{
	public:
		static Matrix4 Frustum(float left, float right, float top, float bottom, float zNear, float zFar);
		static Matrix4 Perspective(float fov, float zNear, float zFar, float aspectRatio);
	};
}
#endif