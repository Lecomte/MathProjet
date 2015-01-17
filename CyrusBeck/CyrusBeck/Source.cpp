#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include <ctime>
#include<stdio.h>
#include<cfloat>
#include "Point.h"
#include<gl\GL.h>

void afficherPoint()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0, 0);
	glVertex2f(0, 1);
	glVertex2f(1, 1);
	glVertex2f(1, 0);

	glColor3f(0.95f, 0.207, 0.031f);
	srand((unsigned int)time(NULL));
	float random=5.0f;
	float X = 0;
	float Y = 0;
	Point poly[32];
	bool save_first_point = false;
	Point firstPoint;
	for (int i = 0; i < 31; i++)
	{
		random = ((float)rand() / (float)(RAND_MAX)) * 500;
		X = random;
		random = ((float)rand() / (float)(RAND_MAX)) * 500;
		Y = random;
		Point p(X, Y);
		if (!save_first_point)
		{
			save_first_point = true;
			firstPoint = p;
		}
		poly[i] = p;
	}
	poly[32] = firstPoint;

	glEnd();
}

bool CyrusBeck(int X1, int Y1, int X2, int Y2, Point poly[], Point normal[], int nbSom)
{
	float tinf = FLT_MIN;
	float tsup = FLT_MAX;
	float DX = X2 - X1;
	float DY = Y2 - Y1;
	float DN = 0.f;
	float WN = 0.f;
	int nbSeg = nbSom - 1;
	Point c;
	float t = 0.f;
	for (int i = 0; i < nbSeg; i++)
	{
		c = poly[i];
		DN = DX * normal[i].x_get() + DY * normal[i].y_get();
		WN = (X1 - c.x_get()) * normal[i].x_get() + (Y1 - c.x_get()) * normal[i].y_get();
		if (DN == 0)
		{
			return WN >= 0;
		}
		else{
			t = -WN / DN;
			if (DN > 0)
			{
				if (t > tinf)
				{
					tinf = t;
				}
			}
			else
			{
				if (t < tsup)
				{
					tsup = t;
				}
			}
		}
	}
	if (tinf < tsup)
	{
		if (tinf < 0 && tsup > 1)
		{
			return true;
		}
		else
		{
			if (tinf > 1 || tsup < 0)
			{
				return false;
			}
			else
			{
				if (tinf < 0)
				{
					tinf = 0.f;
				}
				else
				{
					if (tsup > 1)
					{
						tsup = 1;
					}
				}
				X2 = X1 + DX * tsup;
				Y2 = Y1 + DX * tsup;
				X1 = X1 + DX * tinf;
				Y1 = Y1 + DX * tinf;
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                       // Initialisation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // mode d'affichage RGB, et test prafondeur
	glutInitWindowSize(500, 500);                // dimension fenêtre
	glutInitWindowPosition(100, 100);           // position coin haut gauche
	glutCreateWindow("Un carré dans tous ses états");  // nom

	/* Repère 2D délimitant les abscisses et les ordonnées*/
	gluOrtho2D(-250.0, 250.0, -250.0, 250.0);

	/* Initialisation d'OpenGL */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);       // couleur: blanc
	glPointSize(2.0);

	Point test[32];
	Point test2[32];
	CyrusBeck(5, 5, 6, 6, test, test2, 32);
}