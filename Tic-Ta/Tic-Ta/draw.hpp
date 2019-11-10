#pragma once
#include "gamelIb.h"

void drawCircle(float x, float y, float r, int segment) {
	glBegin(GL_LINE_LOOP); {
		///<Цвет Линий круга>///////
		glColor3f(1.0, 0, 0);//сюда можете розовый вставить или любой другой цвет В RGB формате
		/////////////

		for (int i = 0; i < segment; i++) {
			float angle = 2.0 * PI * (float)i / (float)segment;

			float dx = r * (float)cos(angle);
			float dy = r * (float)sin(angle);

			glVertex2f(dx + x, dy + y);
		}
	}glEnd();
}

void drawCard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j].value != -1) {
				glLineWidth(2);

				if (arr[i][j].value == 0) {
					glBegin(GL_LINES); {
						///<Цвет Линий крестика>///////
						glColor3f(1.0, 0, 0);//сюда можете розовый вставить или любой другой цвет В RGB формате
						/////////////
						glVertex2f(j * scale, i * scale);
						glVertex2f(j * scale + scale, i * scale + scale);

						glVertex2f(j * scale, i * scale + scale);
						glVertex2f(j * scale + scale, i * scale);
					}glEnd();
				}if (arr[i][j].value == 1) {
					drawCircle(j * scale + scale / 2, i * scale + scale / 2, 34, 20);
				}
			}
		}
	}
}
