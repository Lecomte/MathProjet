#include "Point.h"

Point::Point()
{
	this->x_ = 0.f;
	this->y_ = 0.f;
	this->color_ = Color();
}

Point::Point(float x, float y)
{
	this->x_ = x;
	this->y_ = y;
	this->color_ = Color();
}

Point::Point(float x, float y, Color color)
{
	this->x_ = x;
	this->y_ = y;
	this->color_ = color;
}

float Point::x_get()
{
	return this->x_;
}

float Point::y_get()
{
	return this->y_;
}

Color Point::color_get()
{
	return this->color_;
}

bool Point::operator==(Point const& a)
{
	if (this->x_ == a.x_ && this->y_ == a.y_ && this->color_ == a.color_)
	{
		return true;
	}
	return false;
}

Point::~Point()
{
}
