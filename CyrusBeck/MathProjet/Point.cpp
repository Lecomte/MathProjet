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

void Point::x_set(float x)
{
	this->x_ = x;
}
void Point::y_set(float y)
{
	this->y_ = y;
}

Color Point::color_get()
{
	return this->color_;
}

void Point::color_set(Color color)
{
	this->color_ = color;
}

bool Point::operator==(Point const& a)
{
	if (this->x_ == a.x_ && this->y_ == a.y_ && this->color_ == a.color_)
	{
		return true;
	}
	return false;
}

Point Point::operator+(Point const& a)
{
	return Point(a.x_ - this->x_, a.y_ - this->y_);
}

Point Point::operator-(Point const& a)
{
	return Point(a.x_ - this->x_, a.y_ - this->y_);
}

Point::~Point()
{
}
