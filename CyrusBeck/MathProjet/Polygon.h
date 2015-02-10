#pragma once
#include "Point.h"
#include <vector>

class Polygon
{
public:
	Polygon();
	Polygon(std::vector<Point>);
	void addPoint(Point);
	std::vector<Point> points_get();
	float getMinY();
	float getMaxY();
	void points_set(std::vector<Point> points);
	~Polygon();
private:
	std::vector<Point> points_;
};

