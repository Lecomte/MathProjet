#include "Fenetrage.h"


Fenetrage::Fenetrage()
{
}

void Fenetrage::Sutherland_Hodgman()
{
	/*std::cout << "Test 1 " << std::endl;
	Point P1 = Point(0, 5);
	Point P2 = Point(1, 8);
	Point P3 = Point(0,5);
	Point P4 = Point(1, 8);
	if (coupe(P1, P2, P3, P4))
		std::cout << "test 1 coupe." << std::endl;
	else
		std::cout << "test 1 ne coupe pas" << std::endl;
	std::vector<float> column;
	std::vector<std::vector<float>> row;
	column.push_back(P2.x_get() - P1.x_get());
	column.push_back(P2.y_get() - P1.y_get());
	row.push_back(column);
	column.clear();
	column.push_back(P3.x_get() - P4.x_get());
	column.push_back(P3.y_get() - P4.y_get());
	row.push_back(column);
	std::cout << determinant(row) << std::endl;*/
	std::cout << "Test determinant." << std::endl;
	std::vector<float> column;
	std::vector<std::vector<float>> row;
	column.push_back(2);
	column.push_back(-3);
	row.push_back(column);
	column.clear();
	column.push_back(-4);
	column.push_back(1);
	row.push_back(column);
	std::cout << "det : " << determinant(row) << std::endl;
}

bool Fenetrage::coupe(Point p, Point otherPolygonePoint, Point windowPoint, Point windowNextPoint)
{
	float alphaT = otherPolygonePoint.x_get() - p.x_get() + windowPoint.x_get() - windowNextPoint.x_get();
	float alphaS = otherPolygonePoint.y_get() - p.y_get() + windowPoint.y_get() - windowNextPoint.y_get();
	if (sqrt((alphaT * alphaT) + (alphaS * alphaS)) != 0)
		return true;
	return false;
}

float Fenetrage::determinant(std::vector<std::vector<float>> matrice)
{
	float det = 0;
	if (matrice.size() == 2 && matrice[0].size() == 2)
	{
		return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
	}
	else
	{
		//on construit la sous matrice de en éliminant la colonne 0
		//colonne 
		for (std::vector<float>::size_type col = 0; col < matrice[0].size(); col++)
		{
			std::vector<float> colonne;
			std::vector<std::vector<float>> sousMatrice;
			for (int i = 1; i < matrice.size(); i++)
			{
				colonne = std::vector<float>();
				//ligne
				for (std::vector<float>::size_type j = 0; j < matrice[i].size(); j++)
				{
					if (j != col)
						colonne.push_back(matrice[i][j]);
				}
				sousMatrice.push_back(colonne);
			}
			det += pow((-1),col) *(matrice[0][col] * determinant(sousMatrice));
		}
		return det;
	}
}

std::vector<std::vector<float>> comatrice(std::vector<std::vector<float>> matrice)
{
	float newElement = 0;
	if (matrice.size() == 2 && matrice[0].size() == 2)
	{
		return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
	}
	else
	{
		for (std::vector<float>::size_type ligne = 0; ligne < matrice.size(); ligne++)
		{
			for (std::vector<float>::size_type col = 0; col < matrice[ligne].size(); col++)
			{
				std::vector<float> colonne;
				std::vector<std::vector<float>> sousMatrice;
				for (int i = 1; i < matrice.size(); i++)
				{
					colonne = std::vector<float>();
					//ligne
					for (std::vector<float>::size_type j = 0; j < matrice[i].size(); j++)
					{
						if (j != col)
							colonne.push_back(matrice[i][j]);
					}
					sousMatrice.push_back(colonne);
				}
				newElement += pow((-1), col) * comatrice(sousMatrice);
			}
		}
	}
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
