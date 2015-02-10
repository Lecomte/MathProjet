#include "Remplissage.h"


Remplissage::Remplissage()
{
}

std::vector<std::list<Point>> Remplissage::RemplissageLCA(Polygon poly,Color currentColor)
{
	float yMin = poly.getMinY();
	float yMax = poly.getMaxY();
	std::vector<std::list<Point> > fillingPoints;
	std::vector<std::list<LCA>> SI = createSI(poly);

	std::vector<Point> list = poly.points_get();

	std::list<LCA> lca;
	std::list<Point> line;
	std::list<Point> tmpLine;
	std::list<LCA>::iterator lit;

	for (int currY = yMin; currY < yMax; currY++)
	{
		if ((currY - abs(yMin)) < SI.capacity() && !SI.at(currY - abs(yMin)).empty())
		{
			for (lit = SI.at(currY - abs(yMin)).begin(); lit != SI.at(currY - abs(yMin)).end(); ++lit)
				lca.push_back(*lit);
		}

		for (lit = lca.begin(); lit != lca.end(); ++lit)
		{
			if ((*lit).getYMax() <= currY)
				lit = lca.erase(lit);
			if (lit == lca.end())
				break;
		}

		lca.sort();
		for (lit = lca.begin(); lit != lca.end(); ++lit)
		{
			Point _P = Point((*lit).getXMin(), currY, currentColor);
			line.push_back(_P);
			if (2 == line.size())
			{
				Point _p = line.front();
				_p.x_set(_p.x_get() + ((_P.x_get() - _p.x_get()) / 2));
				bool intern2polygon2display = isIntern(_p, list);
				if ((line.front() == line.back()) || intern2polygon2display)
				{
					fillingPoints.push_back(line);
				}
					
				line.clear();
				line.push_back(_P);
			}
			(*lit).setXMin((*lit).getXMin() + (*lit).getInverseCoeffDirecteur());
		}
		line.clear(); // clear line
	}
	return fillingPoints;
}

bool Remplissage::cut(Point &P1, Point &P2, Point &F1, Point &F2)
{
	float s = 0.;
	float t = 0.;
	float numS = ((P1.y_get() - F1.y_get())*(P2.x_get() - P1.x_get()) - (P1.x_get() - F1.x_get())*(P2.y_get() - P1.y_get()));
	float numT = ((P1.y_get() - F1.y_get())*(F2.x_get() - F1.x_get()) - (P1.x_get() - F1.x_get())*(F2.y_get() - F1.y_get()));
	float denominator = ((P2.x_get() - P1.x_get())*(F2.y_get() - F1.y_get()) - (P2.y_get() - P1.y_get())*(F2.x_get() - F1.x_get()));
	if (0. != denominator || 0. != numS)
	{
		t = numT / denominator;
		s = numS / denominator;
		if ((0 <= t && 1 >= t) && (0 <= s && 1 >= s))
			return true;
	}
	return false;
}

bool Remplissage::isIntern(Point &P1, std::vector<Point> &list)
{
	Point I;
	Point P2 = Point(this->getXMax(list) + 10, P1.y_get());
	int nbIntersecs = 0, i = 0;
	bool added = false;
	std::vector<Point>::iterator lit;
	for (lit = list.begin(); lit < list.end(); ++lit)
	{
		Point next = (*lit == list.back()) ? list.front() : list[i + 1];
		if (cut(P1, P2, *lit, next))
		{
			I = Fenetrage().intersec(P1, P2, *lit, next);
			if (I == *lit)
				added = true;
			else if (I == next)
			{
				Point S1 = *lit;
				Point S2 = list [(i + 1 >= list.size()) ? 1 : (i + 2 >= list.size()) ? 0 : i + 2];
				if ((S1.y_get() > I.y_get() && S2.y_get() < I.y_get()) || (S1.y_get() < I.y_get() && S2.y_get() > I.y_get()))
					nbIntersecs++;
				else
					nbIntersecs += 2;

				added = true;
			}
			if (!added)
				nbIntersecs++;
		}
		i++;
		added = false;
	}

	return !(0 == nbIntersecs % 2);
}

float Remplissage::getYMax(std::vector<Point> list)
{
	float yMax = list[0].y_get();
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].y_get() > yMax)
			yMax = list[i].y_get();
	}
	return yMax;
}

float Remplissage::getXMax(std::vector<Point> list)
{
	float xMax = list[0].x_get();
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].x_get() > xMax)
			xMax = list[i].x_get();
	}
	return xMax;
}

float Remplissage::getYMin(std::vector<Point> list)
{
	float yMin = list[0].y_get();
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].y_get() < yMin)
			yMin = list[i].y_get();
	}
	return yMin;
}

std::vector<std::list<LCA>> Remplissage::createSI(Polygon poly)
{
	std::vector<Point> list = poly.points_get();
	float yMax = getYMax(list);
	float yMin = getYMin(list);
	Point first = list[0];
	Point previous;
	std::vector<std::list<LCA> > SI = std::vector< std::list<LCA> >(yMax - yMin + 1);
	std::list<LCA> lca;
	LCA l;
	std::vector<Point>::iterator lit;
	float _yMax, _Xmin, _yMin, _a;

	for (lit = list.begin(); lit != list.end(); ++lit)
	{
		if (first == *lit)
		{
		}
		else
		{
			_yMax = (previous.y_get() > (*lit).y_get()) ? previous.y_get() : (*lit).y_get();
			_Xmin = (previous.y_get() < (*lit).y_get()) ? previous.x_get() : (*lit).x_get();
			_a = (previous.y_get() - (*lit).y_get()) / (previous.x_get() - (*lit).x_get());
			l = LCA(_yMax, _Xmin, 1 / _a);
			_yMin = (previous.y_get() < (*lit).y_get()) ? previous.y_get() : (*lit).y_get();
			try
			{
				(SI.at((int)_yMin - abs(yMin))).push_back(l);
			}
			catch (std::exception& e)
			{
				std::cout << " at() throw exception : index = " << (int)_yMin << "-" << abs(yMin) << " is out of range" << std::endl;
			}
		}
		previous = *lit;
	}
	previous = list.back();
	_yMax = (first.y_get() > previous.y_get()) ? first.y_get() : previous.y_get();
	_Xmin = (first.y_get() < previous.y_get()) ? first.x_get() : previous.x_get();
	_a = (previous.y_get() - first.y_get()) / (previous.x_get() - first.x_get());
	l = LCA(_yMax, _Xmin, ((0 == _a) ? 0 : 1 / _a));
	_yMin = (first.y_get() < previous.y_get()) ? first.y_get() : previous.y_get();
	try
	{
		(SI.at((int)_yMin - abs(yMin))).push_back(l);
	}
	catch (std::exception& e)
	{
		std::cout << " at() throw exception : index = " << (int)_yMin << "-" << abs(yMin) << " is out of range" << std::endl;
	}
	return SI;

}

Remplissage::~Remplissage()
{
}
