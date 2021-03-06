﻿#include <iostream>
using namespace std;

const int Field_x = 20;
const int Field_y = 20;

struct SnakePos {
	int SnakeX=0;
	int SnakeY=0;
};
struct Movement {
	int UP;
	int DOWN;
	int LEFT;
	int RIGHT;
};
Movement Move;
SnakePos Snake;
int MoveUoD() {
	bool UoD;
	char UserUoD;
	cin >> UserUoD;
	if (UserUoD == '8') {
		return(1);
	}
	else if (UserUoD == '5') {
		return(2);
	}
	else if (UserUoD == '6'){
		return(3);
	}
	else if (UserUoD == '4') {
		return(4);
	}
	else {
		exit(0);
	}
}
void DrawSnakeX(char (&Field)[Field_x][Field_y], int counter, int &SnakeX,int &SnakeY) {
	int UoD;
	if (counter == 0) {
		 Snake.SnakeX = 10;
		 Snake.SnakeY = 10;
	}
	else {
		UoD = MoveUoD();
		system("cls");
		if (UoD == 1) {
			Snake.SnakeX = Snake.SnakeX - 1;
		}
		else if (UoD == 2) {
			Snake.SnakeX = Snake.SnakeX + 1;
		}
		else if (UoD == 3) {
			Snake.SnakeY= Snake.SnakeY + 1;
		}
		else if (UoD == 4) {
			Snake.SnakeY = Snake.SnakeY - 1;
		}
	}

}


void DrawField(char(&Field)[Field_x][Field_y]) {
	int counter = 0;
	while (true) {
		DrawSnakeX(Field, counter, Snake.SnakeX, Snake.SnakeY);
		for (int i = 0; i < Field_x; i++) {
			for (int j = 0; j < Field_y; j++) {
				if (i == 0 || i == Field_x - 1) {
					Field[i][j] = '#';
				}
				if (j == 0 || j == Field_y - 1) {
					Field[i][j] = '#';
				}
				if ((i != 0 && i != Field_x - 1) && (j != 0 && j != Field_y - 1)) {
					Field[i][j] = {};
				}
				if (i == Snake.SnakeX && j == Snake.SnakeY) {
					Field[i][j] = 'S';
				}
			}
		}
		for (int i = 0; i < Field_x; i++) {
			for (int j = 0; j < Field_y; j++) {
				cout << Field[i][j];
				if (j == Field_y - 1) {
					cout << endl;
				}
			}
		}
		counter = 1;
	}
}
int main()
{
	char Field[Field_x][Field_y];
	DrawField(Field);
}
