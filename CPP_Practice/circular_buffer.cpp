#include "circular_buffer.hpp"

circular_buffer::circular_buffer(int Size){
	size = Size;
	buffer = vector<char>(size,'f');

}
bool circular_buffer::isFull(){return count == size;}
bool circular_buffer::isEmpty(){return count == 0;}
bool circular_buffer::readChar(char& dest){
	if (!isEmpty()){
		dest = buffer[r_ptr];
		r_ptr = (r_ptr+1) % size;
		count--;
		return true;
	}
	else{
		return false;
	}
}
bool circular_buffer::writeChar(char input){
	if (!isFull()){
		buffer[w_ptr] = input;
		w_ptr = (w_ptr+1) % size;
		count++;
		return true;
	}
	else{
		return false;
	}
}

