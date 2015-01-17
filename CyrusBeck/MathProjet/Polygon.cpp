#include "Polygon.h"


Polygon::Polygon()
{
}

Polygon::Polygon(std::vector<Point> pointTab)
{
	this->points_ = pointTab;
}

void Polygon::addPoint(Point p)
{
	this->points_.push_back(p);
}

std::vector<Point> Polygon::points_get()
{
	return this->points_;
}

Polygon::~Polygon()
{
}
