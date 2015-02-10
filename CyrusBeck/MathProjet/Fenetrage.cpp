#include "Fenetrage.h"


Fenetrage::Fenetrage()
{
}

std::vector<Point> Fenetrage::Sutherland_Hodgman(std::vector<Point> PL, std::vector<Point> PW)
{
	int N2;
	Point F, S, I;
	std::cout << "Sutherland" << std::endl;
	std::vector<Point> PS = std::vector<Point>();
	for (int i = 0; i < PW.size() - 1; i++)
	{
		N2 = 0;
		PS = std::vector<Point>();
		for (int j = 0; j < PL.size(); j++)
		{
			if (j == 0)
			{
				F = PL[j];
			}
			else{
				if (coupe(S, PL[j], PW[i], PW[i + 1],PW))
				{
					I = intersec(S, PL[j], PW[i], PW[i + 1]);
					std::cout << "Ix : " << I.x_get() << "\nIy :" << I.y_get() << std::endl;
					PS.push_back(I);
					N2++;
				}
			}
			S = PL[j];
			if (visible(S, PW[i], PW[i + 1],PW))
			{
				PS.push_back(S);
				N2++;
			}
		}
		if (N2 > 0)
		{
			if (coupe(S, F, PW[i], PW[i + 1],PW))
			{
				I = intersec(S, F, PW[i], PW[i + 1]);
				std::cout << "Ix : " << I.x_get() << "\nIy :" << I.y_get() << std::endl;
				PS.push_back(I);
				N2++;
			}
			PL = PS;
		}
	}
	return PL;
}

/*float matrice[3][3] = { { 0, 1, 2 }, { 1, 1, 2 }, { -1, 1, 1 } };
Matrix matrix = Matrix(matrice);
Matrix commatrice = matrix.comatrice();
commatrice.printMatrix();
commatrice.transpose().printMatrix();
Point P1 = Point(0, 0);
Point P2 = Point(1, 1);
Point P3 = Point(0, 1);
Point P4 = Point(1, 0);
if (coupe(P1, P2, P3, P4))
{
Point intersect = intersection(P1, P2, P3, P4);
std::cout << "intersection a : x(" << intersect.x_get() << ") y(" << intersect.y_get() << ")" << std::endl;
}
if (visible(P1, P3, P4))
std::cout << "P1 visible par rapport a P3 P4" << std::endl;*/

bool Fenetrage::coupe(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint, std::vector<Point> PW)
{
	//Point P1 = Point(otherPolygonePoint.x_get() - p.x_get(), otherPolygonePoint.y_get() - p.y_get());
	//Point P2 = Point(windowPoint.x_get() - windowNextPoint.x_get(), windowPoint.y_get() - windowNextPoint.y_get());
	//
	bool P1visible = visible(p, windowPoint, windowNextPoint,PW);
	bool P2visible = visible(otherPolygonePoint, windowPoint, windowNextPoint,PW);
	//
	if ((P1visible && !P2visible) || (!P1visible && P2visible))
		return true;
	return false;
}

Point Fenetrage::intersection(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint)
{
	float matrice[2][2] = { { otherPolygonePoint.x_get() - p.x_get(), windowPoint.x_get() - windowNextPoint.x_get() },
							{ otherPolygonePoint.y_get() - p.y_get(), windowPoint.y_get() - windowNextPoint.y_get() } };
	float matrix[2][1] = { { windowPoint.x_get() - p.x_get() }, { windowPoint.y_get() - p.y_get() } };
	Matrix m = Matrix(matrice);
	Matrix equalityMatrix = Matrix(matrix);
	Matrix matrixInverse = m.inverse();
	matrixInverse = matrixInverse.produitMatrice(equalityMatrix);
	return Point(matrixInverse.matrix_get()[0][0], matrixInverse.matrix_get()[1][0]);
}

Point Fenetrage::intersec(Point x, Point y, Point x2, Point y2)
{
	Point v = Point(0, 0);
	float s = 0;
	float t = 0;

	float numS = ((x.y_get() - x2.y_get()) * (y.x_get() - x.x_get()) - (x.x_get() - x2.x_get()) * (y.y_get() - x.y_get()));
	float numT = ((x.y_get() - x2.y_get()) * (y2.x_get() - x2.x_get()) - (x.x_get() - x2.x_get()) * (y2.y_get() - x2.y_get()));
	float deno = ((y.x_get() - x.x_get()) * (y2.y_get() - x2.y_get()) - (y.y_get() - x.y_get()) * (y2.x_get() - x2.x_get()));

	if (0. != deno || 0. != numS)
	{
		s = numS / deno;
		t = numT / deno;
		if ((0 <= t && 1 >= t) && (0 <= s && 1 >= s))
		{
			float x1 = x.x_get() + (t * (y.x_get() - x.x_get()));
			float y1 = x.y_get() + (t * (y.y_get() - x.y_get()));
			return Point(x1, y1);
		}
		else if ((1 < s || 0 > s) && (0 <= t && 1 >= t))
		{
			float x2 = x.x_get() + (t * (y.x_get() - x.x_get()));
			float y2 = x.y_get() + (t * (y.y_get() - x.y_get()));
			return Point(x2,y2);
		}
	}
	return v;
}

bool Fenetrage::visible(Point p, Point windowPoint, Point windowNextPoint, std::vector<Point> PW)
{
	float dx = windowNextPoint.x_get() - windowPoint.x_get();
	float dy = windowNextPoint.y_get() - windowPoint.y_get();
	vector2 normal = getInteriorNormal(windowPoint, windowNextPoint, PW);
	//
	vector2 vectorPoint = vector2(p.x_get() - windowPoint.x_get(), p.y_get() - windowPoint.y_get());
	//
	if(normal.prodscal(vectorPoint) > 0)
		return true;
	return false;
}

vector2 Fenetrage::getInteriorNormal(Point windowPoint, Point windowNextPoint, std::vector<Point> PW)
{
	float dx = windowNextPoint.x_get() - windowPoint.x_get();
	float dy = windowNextPoint.y_get() - windowPoint.y_get();
	Point P3;
	for (int i = 0; i < PW.size(); i++)                       // Here we get any point of the polygon
	{                                                                   // wich is not P1 or P2.
		if (PW[i] == windowPoint || PW[i] == windowNextPoint)                                    // Just to be sur that this point is in
			continue;                                                   // the polygon
		else
		{
			P3 = PW[i];
			break;
		}
	}
	vector2 normal1 = vector2(-dy, dx);
	vector2 normal2 = vector2(dy, -dx);
	//
	vector2 vec = vector2(P3.x_get() - windowNextPoint.x_get(), P3.y_get() - windowNextPoint.y_get());
	//
	if (0 < vec.prodscal(normal1))
		return normal1;
	else
		return normal2;
}

Fenetrage::~Fenetrage()
{
}
