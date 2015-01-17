#include "Color.h"

Color::Color()
{
	this->red_ = 0.0f;
	this->green_ = 0.0f;
	this->blue_ = 0.0f;
}

Color::Color(float red, float green, float blue)
{
	this->red_ = red;
	this->green_ = green;
	this->blue_ = blue;
}

float Color::red_get()
{
	return this->red_;
}

float Color::green_get()
{
	return this->green_;
}

float Color::blue_get()
{
	return this->blue_;
}
	
Color::~Color()
{
}
