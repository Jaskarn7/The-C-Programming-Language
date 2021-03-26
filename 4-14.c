#include <stdio.h>

#define INT '!'
#define CHAR '@'
#define FLOAT '#'

#define swap(t, x, y) if (t == INT)  \
                        int temp = x; x = y; y = temp; \
                    else if (t == CHAR) \
                        char temp = x; x = y; y = temp; \
                    else if (t == FLOAT) \
                        float temp = x; x = y; y = temp; \
                    else \
                        printf("Error: Invalid type\n");
