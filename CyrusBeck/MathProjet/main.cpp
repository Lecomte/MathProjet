#include <iostream>
#include <GL\glut.h>
#include <GL\gl.h>
#include "Point.h"
#include <vector>

void mouseClicks(int button, int state, int x, int y);
void affichage();
void createMenu();
void elementSelected(int i);
void init();

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
		std::cout << "x : " << x << " y : " << y << std::endl;
		glPointSize(10);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(x, y);
		glEnd();
		glutSwapBuffers();
	}
}

void affichage(){
	// effacement de l'image avec la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT);

	// On foce l'affichage du résultat
	glFlush();
}

void createMenu()
{
	int menuIndex = glutCreateMenu(elementSelected);
	glutSetMenu(menuIndex);
	glutAddMenuEntry("couleurs", 0);
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
		case 0 :
			std::cout << "couleurs" << std::endl;
			break;
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
}
