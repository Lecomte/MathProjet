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
	bool operator==(Point const& a);
	Point operator+(Point const& a);
	Point operator-(Point const& a);
	~Point();

private:
	float x_;
	float y_;
	Color color_;
};

