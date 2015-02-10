#pragma once
class vector2
{
public:
	vector2(float x, float y);
	float prodscal(vector2 v) { return((x_*v.x_) + (y_*v.y_)); }
	~vector2();
private:
	float x_;
	float y_;
};

