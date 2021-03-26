#include <stdio.h>

int main(void) {
	int prev = 'a', c;
	while ((c = getchar()) != EOF) {
		if (prev == ' ' && c == ' ') prev = ' ';
		else {
			putchar(c);
			 prev = c;
			
		}
	}
}
