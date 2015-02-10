#pragma once
#include "Polygon.h"
#include "Point.h"
#include "Matrix.h"
#include "vector2.h"
#include <math.h>
#include <iostream>
#include <vector>

class Fenetrage
{
public:
	Fenetrage();
	std::vector<Point> Sutherland_Hodgman(std::vector<Point> PL, std::vector<Point> PW);
	bool coupe(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint, std::vector<Point> PW);
	Point intersection(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint);
	Point intersec(Point x, Point y, Point x2, Point y2);
	bool visible(Point p, Point windowPoint, Point windowNextPoint, std::vector<Point> PW);
	~Fenetrage();
private:
	vector2 getInteriorNormal(Point windowPoint, Point windowNextPoint, std::vector<Point> PW);
};