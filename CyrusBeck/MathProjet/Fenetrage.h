#pragma once
#include "Point.h"
#include "Matrix.h"
#include <math.h>
#include <iostream>
#include <vector>

class Fenetrage
{
public:
	Fenetrage();
	void Sutherland_Hodgman();
	~Fenetrage();
private:
	bool coupe(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint);
	Point intersection(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint);
	bool visible(Point p, Point windowPoint, Point windowNextPoint);
};

