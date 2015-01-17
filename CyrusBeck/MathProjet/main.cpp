#include <iostream>
#include <GL\glut.h>

void mouseClicks(int button, int state, int x, int y);
void affichage();
void createMenu();
void elementSelected(int i);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                       // Initialisation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // mode d'affichage RGB, et test prafondeur
	glutInitWindowSize(500, 500);                // dimension fenêtre
	glutInitWindowPosition(100, 100);           // position coin haut gauche
	glutCreateWindow("Math projet");  // nom
	//
	createMenu();
	glutMouseFunc(mouseClicks);
	glutDisplayFunc(affichage);
	//
	glutMainLoop();
	return 0;
}

void mouseClicks(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "bouton gauche cliqué" << std::endl;
	}
}

void affichage(){

	// effacement de l'image avec la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// On foce l'affichage du résultat
	glFlush();
	// On échange les buffers
	glutSwapBuffers();
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
	//std::cout << "element selected : " << index << std::endl;
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
