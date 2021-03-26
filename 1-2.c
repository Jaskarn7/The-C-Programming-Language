#include <stdio.h>

int main(void) {
	printf("hello, world\c");   
	/* Compiler will throw an error, as there is no escape sequence in c std */
	return 0;
}
