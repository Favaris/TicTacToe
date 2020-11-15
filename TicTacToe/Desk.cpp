#include "Desk.h"
#include<iostream>
using namespace std;

Desk::Desk() {
}

void Desk::show() {
	for (int i = 0; i < 3; i++) {
		cout << " ";
		for (int j = 0; j < 3; j++) {
			cout << cells[i][j].getState();
			if (j < 2) {
				cout << " | ";
			}
		}
		if (i < 2) {
			cout << "\n-----------";
		}
		cout << "\n";
	}
}

void Desk::hide() {
	system("cls");
}

bool Desk::checkWin(char state) {
	for (int i = 0; i < 3; i++) {
		if (cells[i][0].getState() == state && cells[i][1].getState() == state && cells[i][2].getState() == state) {
			return true;
		}
		if (cells[0][i].getState() == state && cells[1][i].getState() == state && cells[2][i].getState() == state) {
			return true;
		}
	}
	if (cells[0][0].getState() == state && cells[1][1].getState() == state && cells[2][2].getState() == state) {
		return true;
	}
	if (cells[0][2].getState() == state && cells[1][1].getState() == state && cells[2][0].getState() == state) {
		return true;
	}
	return false;
}

void Desk::fillCell(int x, int y, char state) {
	cells[x][y].setState(state);
}

bool Desk::checkCell(int x, int y) {
	if (cells[x][y].getState() != '-') {
		return false;
	}
	return true;
}