#include"Cell.h"
#include"Desk.h"
#include<iostream>
using namespace std;

void takeTurn(int& x, int& y) {
	int n;
	cin >> n;
	while (n < 1 || n>9) {
		cout << "Choose between 1 and 9!\n";
		cin >> n;
	}
	switch (n)	//positions of numpad keys to positions of cells on the desk
	{
	case 1: {
		x = 2;
		y = 0;
		break;
	}
	case 2: {
		x = 2;
		y = 1;
		break;
	}
	case 3: {
		x = 2;
		y = 2;
		break;
	}
	case 4: {
		x = 1;
		y = 0; 
		break;
	}
	case 5: {
		x = 1;
		y = 1;
		break;
	}
	case 6: {
		x = 1;
		y = 2;
		break;
	}
	case 7: {
		x = 0;
		y = 0;
		break;
	}
	case 8: {
		x = 0;
		y = 1;
		break;
	}
	case 9: {
		x = 0;
		y = 2;
		break;
	}
	default:
		break;
	}
}

int main() {
	Desk desk;
	
	bool gameIsOn = true;
	char whichTurn = 'X';
	desk.show();
	int turnscount = 1;
	do {
		int x, y;
		takeTurn(x, y);
		while (!desk.checkCell(x, y)) {
			cout << "This cell is already filled. Try another one.\n";
			takeTurn(x, y);
		}
		if (whichTurn == 'X') {
			desk.hide();
			desk.fillCell(x, y, 'X');
			desk.show();
			gameIsOn = !desk.checkWin('X');
			whichTurn = 'O';
		}
		else {
			desk.hide();
			desk.fillCell(x, y, 'O');
			desk.show();
			gameIsOn = !desk.checkWin('O');
			whichTurn = 'X';
		}
		turnscount++;
	} while (gameIsOn==true && turnscount<=9);

	if (gameIsOn == true && turnscount > 9) {
		cout << "\nDraw!\n";
	}
	else if (desk.checkWin('X')) {
		cout << "\nX player wins!!\n";
	}
	else if (desk.checkWin('O')) {
		cout << "\nO player wins!!\n";
	}

	return 0;
}