#include "Fenetrage.h"


Fenetrage::Fenetrage()
{
}

void Fenetrage::Sutherland_Hodgman()
{
	std::vector<float> column;
	std::vector<std::vector<float>> row;
	float matrice[3][3] = { { 0, 1, 2 }, { 1, 1, 2 }, { -1, 1, 1 } };
	Matrix matrix = Matrix(matrice);
	Matrix commatrice = matrix.comatrice();
	commatrice.printMatrix();
	commatrice.transpose().printMatrix();
}

bool Fenetrage::coupe(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint)
{
	float matrice[2][2] = { { otherPolygonePoint.x_get() - p.x_get(), windowPoint.x_get() - windowNextPoint.x_get() },
							{ otherPolygonePoint.y_get() - p.y_get(), windowPoint.y_get() - windowNextPoint.y_get() } };
	Matrix m = Matrix(matrice);
	if (m.determinant() != 0)
		return true;
	return false;
}

Point Fenetrage::intersection(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint)
{

	return Point();
}

bool Fenetrage::visible(Point p, Point windowPoint, Point windowNextPoint)
{
	return true;
}

Fenetrage::~Fenetrage()
{
}
