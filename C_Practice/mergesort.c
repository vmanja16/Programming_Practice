#include <stdio.h>
#include <string.h>


void merge(int * arr, int low, int high){
	int mid = (high+low)/2;
	int lowSize = mid - low + 1; 
	int highSize = high - mid;
	
	int lowHalf[lowSize]; 
	int highHalf[highSize]; 
	
	// Copy contents into temporary arrays
	 memcpy(lowHalf, arr+low, (lowSize) * sizeof(int));
	 memcpy(highHalf, arr+mid+1, (highSize) * sizeof(int));
	
	int i = 0;
	int j = 0;
	int k = low;
	
	
	
	// Compare and Sort here
	while(1){
		if(lowHalf[i] < highHalf[j]){
			arr[k] = lowHalf[i];
			i++;
			k++;
			if(i==lowSize) break;
		}else{
			arr[k] = highHalf[j];
			j++;
			k++;
			if(j==highSize) break;
		}
		
	}
	// Finish copying
	while(i<lowSize){
		arr[k] = lowHalf[i];
		i++;
		k++;
	}
	while(j<highSize){
		arr[k] = highHalf[j];
		j++;
		k++;
	}	

}

void msort(int * arr, int low, int high){
	int mid = (high+low)/2;
	
	if (high>low){
		msort(arr, low, mid);
		msort(arr, mid+1, high);
		merge(arr, low, high);
	}
}


void mergesort(int * arr, int len){
	msort(arr, 0, len-1);
} 


int main(void){
	
	int x [] = {9,8,7,1,2,3,6,5,4};
	mergesort(x, 9);
	
	int i = 0;
	
	for (i = 0; i< 9; i++){
		printf("%d ", x[i]);
	}
	
	
	return 0;
}
