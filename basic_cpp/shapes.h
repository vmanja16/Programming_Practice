#include <iostream>
using namespace std;

class Shape{
	
	public:
	 Shape(){cout<< "A Shape was created!" << endl;}

	 virtual void numSides(){
	 	cout << "Generic # of sides";
	 }
};

class  Square : public Shape {

	private: int sides = 4; 

	public:
	 Square(){cout << "A square!" << endl;}

	 void numSides(){
	 	cout << sides;
	 }


};
