#pragma once
#include <iostream>
#include <list>
#include "LCA.h"
#include "Polygon.h"
#include "Fenetrage.h"

class Remplissage
{
public:
	Remplissage();
	std::vector<std::list<Point>> RemplissageLCA(Polygon poly, Color currentColor);
	std::vector<std::list<LCA>> createSI(Polygon poly);
	~Remplissage();
private:
	float getYMax(std::vector<Point> list);
	float getXMax(std::vector<Point> list);
	float getYMin(std::vector<Point> list);
	bool cut(Point &P1, Point &P2, Point &F1, Point &F2);
	bool isIntern(Point &P1, std::vector<Point> &list);
};

