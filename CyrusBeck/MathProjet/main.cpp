#include <iostream>
#include <GL\glut.h>
#include <GL\gl.h>
#include "Point.h"
#include "Polygon.h"
#include <vector>

void mouseClicks(int button, int state, int x, int y);
void affichage();
void createMenu();
void elementSelected(int i);
void newPolygon();
void colorMenu(int index);
void changeColor(float red, float green, float blue);
void init();
Color currentColor;

int drawingMode;
Polygon* currentPoly;
std::vector<Polygon*> polygonArray;
std::vector<Point> pointArray;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                       // Initialisation
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);                // dimension fenêtre
	glutInitWindowPosition(100, 100);           // position coin haut gauche
	glutCreateWindow("Math projet");  // nom
	//
	createMenu();
	glutMouseFunc(mouseClicks);
	glutDisplayFunc(affichage);
	//
	init();
	glutMainLoop();
	return 0;
}

void mouseClicks(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		y = 500 - y;
		Point p = Point(x, y, currentColor);
		if (drawingMode == GL_POINTS)
		{
			pointArray.push_back(p);
		}
		else if (drawingMode == GL_POLYGON)
		{
			currentPoly->addPoint(p);
		}
		glutPostRedisplay();
	}
}

void affichage(){
	// effacement de l'image avec la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);
	//draw point
	glBegin(GL_POINTS);
	for (std::vector<Point>::size_type i = 0; i < pointArray.size(); i++)
	{
		Point p = pointArray[i];
		glColor3f(p.color_get().red_get(), p.color_get().green_get(), p.color_get().blue_get());
		glVertex2f(p.x_get(),p.y_get());
	}
	glEnd();

	//draw poly
	for (std::vector<Polygon>::size_type i = 0; i < polygonArray.size(); i++)
	{
		glBegin(GL_POLYGON);
		std::vector<Point> polygonPoints = polygonArray[i]->points_get();
		for (std::vector<Point>::size_type j = 0; j < polygonPoints.size(); j++)
		{
			Point p = polygonPoints[j];
			glColor3f(p.color_get().red_get(), p.color_get().green_get(), p.color_get().blue_get());
			glVertex2f(p.x_get(), p.y_get());
		}
		glEnd();
	}
	

	glutSwapBuffers();

	// On foce l'affichage du résultat
	glFlush();
}

void createMenu()
{
	int menuIndex = glutCreateMenu(elementSelected);
	//couleur menu
	int submenu = glutCreateMenu(colorMenu);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Custom", 3); //a implementer plus tard
	//menu principal
	glutSetMenu(menuIndex);
	glutAddSubMenu("couleurs", submenu);
	glutAddMenuEntry("polygone a decouper", 1);
	glutAddMenuEntry("tracer fenetre", 2);
	glutAddMenuEntry("fenetrage", 3);
	glutAddMenuEntry("remplissage", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void elementSelected(int index)
{
	switch (index)
	{
		case 1 :
			newPolygon();
			break;
		case 2 :
			std::cout << "tracer fenetre" << std::endl;
			break;
		case 3 :
			std::cout << "fenetrage" << std::endl;
			break;
		case 4 :
			std::cout << "remplissage" << std::endl;
			break;
		default:
			std::cout << "index non reconnu" << std::endl;
			break;
	}
}

void newPolygon()
{
	if (drawingMode == GL_POINTS)
	{
		drawingMode = GL_POLYGON;
		currentPoly = new Polygon();
		polygonArray.push_back(currentPoly);
	}
	else{
		drawingMode = GL_POINTS;
	}

}

void colorMenu(int index)
{
	switch (index)
	{
		case 0 :
			changeColor(1.0, 0.0, 0.0);
			break;
		case 1:
			changeColor(0.0, 1.0, 0.0);
			break;
		case 2:
			changeColor(0.0, 0.0, 1.0);
			break;
		default:
			std::cout << "couleur non repertorie." << std::endl;
	}
}

void changeColor(float red,float green, float blue)
{
	currentColor = Color(red, green, blue);
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	//glOrtho(0.0, 500.0, 0.0, 500.0, 1.0, -1.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawingMode = GL_POINTS;
	currentColor = Color(1.0, 0.0, 0.0);
}
