#pragma once
#include"Cell.h"

class Desk{
private:
	Cell cells[3][3];
public:
	Desk();
	void show();
	void hide();
	bool checkWin(char);
	void fillCell(int, int, char);
	bool checkCell(int, int);
};
