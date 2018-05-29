#include <stdio.h>


unsigned int reverseAllBits(unsigned int number){
	unsigned int reversedNumber = 0;
	int NUM_BITS_INDEX = sizeof(number) * 8 - 1;
	int i = 0;
	while(number > 0){
		if (number & 1)  reversedNumber |=  (1<<(NUM_BITS_INDEX-i));
		number >>= 1; 
		i++; 
	}
	return reversedNumber;
}

unsigned int getOnesMask(int msi, int lsi){
	unsigned int mask = (1<<(msi+1)) - 1; // 0111111
	mask &= ((~0) << lsi);                // 0111100
	return mask;
}
unsigned int getZerosMask(int msi, int lsi){
	return ~getOnesMask;
}


/* Reverses bits between the most significant and least signifant indexes of the integer 
   Assumes 0-indexing
  
unsigned int reverseBits(unsigned int number, int msi, int lsi){
	return (number & (~mask))  | (reversedNumber & mask);	
}
 */
/* Swaps the even and odd index bits in a number */
int pairwiseSwap(int number){
	return ((number & 0xAAAAAAAA) >> 1) | ((number & 0x55555555) << 1);
}


int main(void){
	unsigned int num =  0xAFFFF;
	int num2 = 0x8888AAAA;

	printf("%x\n", reverseAllBits(num2));
	printf("%x\n", reverseBits(num2,15,0));
	printf("%x\n", reverseAllBits(num));
	printf("%x\n", pairwiseSwap(num2));


	return 0;
}