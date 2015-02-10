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

void Polygon::points_set(std::vector<Point> points)
{
	this->points_ = points;
}

float Polygon::getMinY()
{
	float yMin = this->points_[0].y_get();
	for (int i = 1; i < this->points_.size(); i++)
	{
		if (this->points_[i].y_get() < yMin)
			yMin = this->points_[i].y_get();
	}
	return yMin;
}

float Polygon::getMaxY()
{
	float yMax = this->points_[0].y_get();
	for (int i = 1; i < this->points_.size(); i++)
	{
		if (this->points_[i].y_get() > yMax)
			yMax = this->points_[i].y_get();
	}
	return yMax;
}

Polygon::~Polygon()
{
}
