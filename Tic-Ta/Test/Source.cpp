#include <glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES); {
		glColor3f(1.0, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(99, 99);
	}glEnd();

	glutSwapBuffers();
}

void Init() {
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 100, 0);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("AAA");

	Init();

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}