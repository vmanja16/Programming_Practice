#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

#define getMax(a,b) ((a>b) ? a : b)
#define getMin(a,b) ((a<b) ? a : b)

int sum (int count,...) {
    va_list args;
    va_start(args,count);
    int summation = 0;
    for (int i = 0; i < count; i++){
        summation += va_arg(args,int);
    }

    return summation;

}

int min(int count,...) {
    int minimum =  MAX_ELEMENT;
    int num;
    va_list args;
    va_start(args,count);
     for (int i = 0; i < count; i++){
        num = va_arg(args,int);
        minimum = getMin(minimum,num);
     }

    return minimum;

}

int max(int count,...) {
    int maximum = MIN_ELEMENT;
    int num;
    va_list args;
    va_start(args,count);
    for (int i = 0; i < count; i++){
        num = va_arg(args,int);
        maximum = getMax(maximum,num);
     }

    return maximum;

}
