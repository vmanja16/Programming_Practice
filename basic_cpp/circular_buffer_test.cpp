#include "circular_buffer.hpp"


# define BUFFER_SIZE 10

int main (void){


	cout << "Beginning Test" << endl;

	circular_buffer buff = circular_buffer(BUFFER_SIZE);
	char test_char;

	// fill the buffer
	for (int i = 0; i < BUFFER_SIZE; i++){
		buff.writeChar();
	}


	if(!buff.isFull()){
		cout << "Full Test failed" << endl;
	}

	if (buff.writeChar('n')){
		cout << "Attempted to write on Full Buffer" << endl;
	}

	if(!buff.readChar(test_char)){
		cout << "Read failed" << endl;
	}

	cout << test_char << endl;


	//circular_buffer.print();



	return 0;
}