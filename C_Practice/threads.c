#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 25
 
// GLobal variable
int g = 0;
 
/* Practice function pointers here */
void inc(int * a){*a = *a+1;}
void dec(int * a){*a = *a-1;}
// Increment/Decrement s if id is even/odd
void functionChooser(int id, int * var){
	static void(*fptr[])(int *) = {inc, dec};
	(*fptr[id & 1])(var);
}
/* End function pointers*/

// A wait function
void wait(int loops){
	int h;
	for (int j =0; j < loops*100000; j++){
		h++;
	}
}

// The function to be executed by all threads
void *	worker(void *vargp)
{
    // Store the value argument 
    int threadID = *(int *) vargp;

    // static var s
    static int s = 0;
    
    // ENTER
    printf("ENTER: Thread ID: %d, Static: %d, Global: %d\n", threadID, s, g);

    wait(1000);
    
    // Change vars 	
 	functionChooser(threadID, &s); // change s
 	g++;

    // EXIT
    wait(1000);
    printf("EXIT : Thread ID: %d, Static: %d, Global: %d\n", threadID, s, g);

    pthread_exit(NULL);
    return NULL;
}
 
int main()
{
    int i;
    // Thread ID array
    int thread_id[NUM_THREADS];
    // Thread Array
    pthread_t threads [NUM_THREADS];

    // The thread creation
    for (i = 0; i < NUM_THREADS; i++){
    	thread_id[i] = i;
    	/* Create (pthread_t * thread, pthread_attr attr, (void *)(), void * arg) */
        pthread_create(&threads[i], NULL, worker, &thread_id[i]);
    }
    // Wait for All Threads to finish.
 	for (i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
 	}
    
    pthread_exit(NULL);
    return 0;
}