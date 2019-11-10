#pragma once
#include "gamelIb.h"
using namespace std;
int st = 0;

int Vertical(int row, int col) {
	bool state = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i][col].value != player) {
			state = 1;
			break;
		} else {
			count++;

			if (count == 3) {
				st = arr[i][col].value;
				return count;
			}
		}
	}

	if (!state) {
		cout << "Fa";
	}
}

int Horizontal(int row, int col) {
	bool state = 0;
	int count = 0;

	for (int i = 0; i < m; i++) {
		if (arr[row][i].value != player) {
			state = 1;
			break;
		} else {
			count++;

			if (count == 3) {
				st = arr[row][i].value;
				return count;
			}
		}
	}

	if (!state) {
		cout << "Fa";
	}
}

int mainDiagonal() {
	bool state = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i][i].value != player) {
			state = 1;
			break;
		} else {
			count++;

			if (count == 3) {
				st = arr[i][i].value;
				return count;
			}
		}
	}

	if (!state) {
		cout << "Fa";
	}
}

int Diagonal() {
	bool state = 0;
	int count = 0;

	for (int i = 0, j = m - 1; j >= 0; i++, j--) {
		if (arr[i][j].value != player) {
			state = 1;
			break;
		} else {
			count++;

			if (count == 3) {
				st = arr[i][j].value;;
				return count;
			}
		}
	}

	if (!state) {
		cout << "Fa";
	}
}

void checkAll() {
	if (countCard >= n * m - 1) {
		cout << "Ничья" << endl;
	}
}

int getStateWin() {
	return st;
}