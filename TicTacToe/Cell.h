#pragma once
class Cell {
public:
	Cell();
	char getState();
	void setState(char);
private:
	char state = '-'; 
};

