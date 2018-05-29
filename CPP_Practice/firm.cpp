#include <iostream>
#include <vector>


using namespace std;

int counBitsSet(unsigned int number){

	int count = 0;
	while (number > 0){
		if (number & 0x01){count++;}
		number >>= 1;
	}
	return count;
}



unsigned char swapNibbles(unsigned char number){
	return (number >> 4) | (number << 4);

};

// position 0 is LSB
int clearBit(int number, int position){
	return number &  ~( 1 << position );
}
int setBit(int number, int position){
	return number | (1 << position);
}
int toggleBit(int number, int position){
	return number ^ (1 << position);
}
int updateBit(int number, int position, boolean bit)
	/*
	if (bit) return setBit(number,position);
	else return clearBit(number,position);
	*/

	int val =  bit ? 1 : 0;
	val <<= position;
	return number & (~(1 << position)) | val; 


void URLify(char * url, int length){
	// replace the spaces with '%20'
	
}

int main (void){

	// swap two values using XOR
	int x = 10, y = 5;
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;

	unsigned char num = 0b00001111;
	unsigned char swapped = swapNibbles(num);
	printf("%x\n", num);
	printf("swapped is %x\n", swapped);


	int b = -7; b >>= 1;
	printf("%d\n", b);
	return 0;
}