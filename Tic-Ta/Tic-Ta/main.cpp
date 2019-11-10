#include "gamelIb.h"

using namespace std;

void printCard() { //������ �������� �������� � ������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j].value << " ";
		}

		cout << endl;
	}
}

void win(int value) {
	int winState;

	switch (value) {
	case 1://ver
		drawCard();
		winState = getStateWin();

		if (winState == 0) {
			//�����
			cout << "�������� �������� �� ���������";
		} else if (winState == 1){
			//�����
			cout << "�������� ������ �� ���������";
		}

		break;
	case 2://hor
		drawCard();
		winState = getStateWin();

		if (winState == 0) {
			//�����
			cout << "�������� �������� �� �����������";
		} else if (winState == 1) {
			//�����
			cout << "�������� ������ �� �����������";
		}

		break;
	case 3://mainD
		drawCard();
		winState = getStateWin();

		if (winState == 0) {
			//�����
			cout << "�������� �������� �� ���������";
		} else if (winState == 1) {
			//�����
			cout << "�������� ������ �� ���������";
		}

		break;
	case 4://diag
		drawCard();
		winState = getStateWin();

		if (winState == 0) {
			//�����
			cout << "�������� �������� �� ���������";
		} else if (winState == 1) {
			//�����
			cout << "�������� ������ �� ���������";
		}

		break;
	}

	glClearColor(0, 0, 0, 1);
	glutTimerFunc(2500, exit, 0);
}

void Draw() {
	glBegin(GL_LINES); {
		///<���� ����� "�����">///////
		glColor3f(1.0, 0, 0);//���� ������ ������� �������� ��� ����� ������ ���� � RGB �������
		/////////////
		for (int i = 0; i < width; i += scale) {
			glVertex2f(i, 0);
			glVertex2f(i, height);
		}

		for (int i = 0; i < height; i += scale) {
			glVertex2f(0, i);
			glVertex2f(width, i);
		}
	} glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
		Draw();
		drawCard();
	glutSwapBuffers();
}

void Init() {
	///<���� ���� ���>///////
	glClearColor(0.7, 0.7, 0.7, 1);//���� ������ ������� �������� ��� ����� ������ ���� � RGB ������� �� ����� ����� �� ��������
	///////////////////////
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timer(int value = 0) {
	display();
	glutTimerFunc(100, timer, 0);
}

void MousePress(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//cout << x << "   " << y << endl;
		int row = y / scale;
		int col = x / scale;

		if (arr[row][col].value == -1) {
			arr[row][col].value = player;
			
			printCard();
		}
		else return;

		int ver = Vertical(row, col);
		int hor = Horizontal(row, col);
		int maD = mainDiagonal();
		int diag = Diagonal();

		if (ver == 3)win(1);
		if (hor == 3)win(2);
		if (maD == 3)win(3);
		if (diag == 3)win(4);

		//if (Win == 3)win();

		checkAll();

		player = !player;
		++countCard;
	}
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Russian");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Tic-Tac");

	Init();

	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);
	glutMouseFunc(MousePress);
	glutPostRedisplay();
	glutMainLoop();
	
	return 0;
}