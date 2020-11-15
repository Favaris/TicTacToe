#include "Cell.h"
#include<iostream>
using namespace std;

Cell::Cell() {
}

char Cell::getState() {
	return state;
}

void Cell::setState(char state) {
	this->state = state;
}
