#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <random>

const int size = 10;
char board[size][size];

int playerY = size / 2;
int playerX = size / 2;

int appleY = 0;
int appleX = 0;

int count = 0;

const int arrayTop = 72;
const int arrayBottom = 80;
const int arrayLeft = 75;
const int arrayRight = 77;

void initBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			(i == 0 || j == 0 || i == size - 1 || j == size - 1) ? board[i][j] = '*' : board[i][j] = ' ';
		}
	}
}

std::mt19937 gen(std::random_device{}());
std::uniform_int_distribution<int> dist(1, size - 2);

void spawnApple() {
	do {
		appleX = dist(gen);
		appleY = dist(gen);
	} while (appleX == playerX && appleY == playerY);
}

void paintBoard() {
	system("cls");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == playerY && j == playerX) std::cout << '@' << ' ';
			else if (i == appleY && j == appleX) std::cout << '&' << ' ';
			else std::cout << board[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "The dog eated: " << count << " apples";
}

bool canMovie(int x, int y) {
	return x > 0 && y > 0 && x < size - 1 && y < size - 1;
}

void handleInput(int key) {
	int newX = playerX;
	int newY = playerY;
	if (key == arrayTop) newY--;
	else if (key == arrayBottom) newY++;
	else if (key == arrayLeft) newX--;
	else if (key == arrayRight) newX++;
	if (canMovie(newX, newY)) {
		playerX = newX;
		playerY = newY;
	}
}

int main() {
	initBoard();
	spawnApple();
	paintBoard();

	while (true) {
		int arrow = _getch();
		handleInput(arrow);
		if (playerX == appleX && playerY == appleY) {
			spawnApple();
			count++;
		}
		paintBoard();
	}

	return 0;
}