#pragma once
#include "Point.h"
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
	float determinant(std::vector<std::vector<float>> matrice);
	std::vector<std::vector<float>> comatrice(std::vector<std::vector<float>> matrice);
	Point intersection(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint);
	bool visible(Point p, Point windowPoint, Point windowNextPoint);
};

