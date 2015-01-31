#include "Point.h"


Point::Point()
{
	this->x_ = 0.f;
	this->y_ = 0.f;
}

Point::Point(float x, float y)
{
	this->x_ = x;
	this->y_ = y;
}

float Point::x_get()
{
	return this->x_;
}

float Point::y_get()
{
	return this->y_;
}

Point::~Point()
{
}
