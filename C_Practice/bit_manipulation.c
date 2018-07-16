#include <stdio.h>

// Bit Patterns
#define ALT   0xAAAAAAAA
#define ALT_2 0xCCCCCCCC
#define ALT_4 0xF0F0F0F0


# define setBit(num,pos) (num | (1 << pos))
# define clearBit(num,pos) (num & ~(1 << pos))
# define toggleBit(num,pos) (num ^ (1 << pos))


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


int reverse_8(unsigned int num){
    num = ((num & ALT)   >> 1) | ((num<<1) & ALT);
    num = ((num & ALT_2) >> 2) | ((num<<2) & ALT_2);
    num = ((num & ALT_4) >> 4) | ((num<<4) & ALT_4);
    return num;
}

unsigned int getOnesMask(int msi, int lsi){
	unsigned int mask = (1<<(msi+1)) - 1; // 0111111
	mask &= ((~0) << lsi);                // 0111100
	return mask;
}
unsigned int getZerosMask(int msi, int lsi){
	return ~getOnesMask(msi, lsi);
}

/* Swaps the even and odd index bits in a number */
int pairwiseSwap(int number){
	return ((number & 0xAAAAAAAA) >> 1) | ((number & 0x55555555) << 1);
}


int main(void){
	unsigned int num =  0xAFFFF;
	int num2 = 0x8888AAAA;
	int test_var = 0b0010;
	/* Test Macros */
	printf("%x\n", setBit(test_var, 3));
	printf("%x\n", clearBit(test_var, 1));
	printf("%x\n", setBit(test_var, 3));
	/* Test functions */
	printf("%x\n", reverseAllBits(num2));
	printf("%x\n", reverseAllBits(num));
	printf("%x\n", pairwiseSwap(num2));


	return 0;
}
