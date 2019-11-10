#include <glut.h>

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES); {
		glColor3f(1, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(1, 1);
	}glEnd();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("AAAAAAAAAAAAAAAAA");

	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}