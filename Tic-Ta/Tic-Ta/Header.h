#pragma once
#include "gamelIb.h"

#define PI 3.1415926

const int n = 5;
const int m = 5;

int scale = 70;
const int width = m * scale;
const int height = n * scale;

bool player = 0;
int countCard = 0;

struct Card {
	int x;
	int y;
	int value;

	Card();
}arr[n][m];

Card::Card() { value = -1; }