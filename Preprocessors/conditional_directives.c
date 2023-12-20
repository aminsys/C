#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define ADD(x,y) x + y
#undef ADD

void perform_add(float a, float b){
    #ifdef ADD
        printf("Sum = %.2f\n", ADD(a,b));
    #endif

    #ifndef ADD
        printf("ADD is not defined\n");
    #endif
}

float perform_computation(float a, float b, float c){
    float r1 = a + b + c;
    float r2 = a * b * c;

    #if DEBUG == 1
        printf("r1: %.3f\n", r1);
        printf("r2: %.3f\n", r2);
        printf("Total is: %.3f\n", r1 + r2);
    #elif DEBUG == 2
        printf("Total is: %.3f\n", r1 + r2);
    #endif

    return r1 * r2;
}

int main(){

    float a = 102.34023, b = 243.4503, c = 19.1002;
    printf("Result of 'Perform Computation(a,b,c)' is: %.3f\n", perform_computation(a, b, c));

    printf("Performing ADD:\n");
    perform_add(102.342, 32.001);
    
    return EXIT_SUCCESS;
}