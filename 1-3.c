#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
    printf("Fahr\t Celsius\n");
    for (int fahr = LOWER; fahr<=UPPER; fahr += STEP) 
        printf("%3d\t%6.1f\n", fahr, ((5.0/9.0)*(fahr-32.0)));
    return 0;
}