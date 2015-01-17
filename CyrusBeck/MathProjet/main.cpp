#include <iostream>
#include <GL\glut.h>
#include <GL\gl.h>
#include "Point.h"
#include <vector>

void mouseClicks(int button, int state, int x, int y);
void affichage();
void createMenu();
void elementSelected(int i);
void colorMenu(int index);
void changeColor(float red, float green, float blue);
void init();
Color currentColor;

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
		pointArray.push_back(Point(x, y, currentColor));
		glutPostRedisplay();
	}
}

void affichage(){
	// effacement de l'image avec la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);
	for (std::vector<Point>::size_type i = 0; i < pointArray.size(); i++)
	{
		glBegin(GL_POINTS);
		Point p = pointArray[i];
		glColor3f(p.color_get().red_get(), p.color_get().green_get(), p.color_get().blue_get());
		glVertex2f(p.x_get(),p.y_get());
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
			std::cout << "polygone a decouper" << std::endl;
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
			std::cout << "couleur non reportorie." << std::endl;
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
	glOrtho(0.0, 500.0, 0.0, 500.0, 1.0, -1.0);
	//gluOrtho2D(0.0, 500.0, 0.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	currentColor = Color(1.0, 0.0, 0.0);
}
