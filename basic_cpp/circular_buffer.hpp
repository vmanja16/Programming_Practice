#include <iostream>
#include <vector>

using namespace std;


class circular_buffer{

	private:
		int r_ptr = 0;
		int w_ptr = 0;
		bool empty = true;
		bool full = false;
		int count = 0;
		int size;
		vector<char> buffer;
	public:
	
		bool isFull();
		bool isEmpty();
		circular_buffer(int);
		// returns char if successfull, else -1
		bool readChar(char& x);
		// true if successfull, false if full
		bool writeChar(char input);

		void print();



};