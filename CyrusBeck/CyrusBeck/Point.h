#pragma once
class Point
{
public:
	Point();
	Point(float, float);
	float x_get();
	float y_get();
	~Point();

private:
	float x_;
	float y_;
};

