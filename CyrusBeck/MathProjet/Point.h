#pragma once
#include "Color.h"

class Point
{
public:
	Point();
	Point(float, float);
	Point(float, float,Color);
	float x_get();
	float y_get();
	Color color_get();
	~Point();

private:
	float x_;
	float y_;
	Color color_;
};

