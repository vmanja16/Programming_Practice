#include <iostream>
#include "shapes.h"
using namespace std;


int main () {

	cout << "Hello World" << endl << endl;

	Shape x = Shape();
	Square s = Square();

	x.numSides();
	s.numSides();

	Shape * ptr = &s;
	(*ptr).numSides();

	return 0;
}