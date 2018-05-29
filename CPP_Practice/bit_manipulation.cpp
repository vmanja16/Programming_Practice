#include <iostream>
#include <vector>


using namespace std;

int insert(int M, int N, int i, int j);



/* insert M into N at position j->i */
int insert(int M, int N, int i, int j){
	int insertVal = M << j;
	// Creat Mask
	int mask = 0;
	for (int c = i; c < j+1; c++){
		mask |= (1 << c);
	} 
	// makes 1's everywhere but j->i
	mask = ~mask; 

	return (N & mask) | insertVal;
}

int main(void){


	int N = 0b10000000000, M = 0b10011;

	printf("%x inserted into %x\n becomes %x", M, N, insert(M,N,0, 4) );


	return 0;
}