#include "Fenetrage.h"


Fenetrage::Fenetrage()
{
}

void Fenetrage::Sutherland_Hodgman()
{
	/*float matrice[3][3] = { { 0, 1, 2 }, { 1, 1, 2 }, { -1, 1, 1 } };
	Matrix matrix = Matrix(matrice);
	Matrix commatrice = matrix.comatrice();
	commatrice.printMatrix();
	commatrice.transpose().printMatrix();*/
	Point P1 = Point(0, 0);
	Point P2 = Point(1, 1);
	Point P3 = Point(0, 1);
	Point P4 = Point(1, 0);
	if (coupe(P1, P2, P3, P4))
	{
		Point intersect = intersection(P1, P2, P3, P4);
		std::cout << "intersection a : x(" << intersect.x_get() << ") y(" << intersect.y_get() << ")" << std::endl;
	}
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
	float matrice[2][2] = { { otherPolygonePoint.x_get() - p.x_get(), windowPoint.x_get() - windowNextPoint.x_get() },
							{ otherPolygonePoint.y_get() - p.y_get(), windowPoint.y_get() - windowNextPoint.y_get() } };
	float matrix[2][1] = { { windowPoint.x_get() - otherPolygonePoint.x_get() }, { windowPoint.y_get() - otherPolygonePoint.y_get() } };
	Matrix m = Matrix(matrice);
	Matrix equalityMatrix = Matrix(matrix);
	Matrix matrixInverse = m.inverse();
	matrixInverse = matrixInverse.produitMatrice(equalityMatrix);
	return Point(matrixInverse.matrix_get()[0][0], matrixInverse.matrix_get()[1][0]);
}

bool Fenetrage::visible(Point p, Point windowPoint, Point windowNextPoint)
{
	return true;
}

Fenetrage::~Fenetrage()
{
}
