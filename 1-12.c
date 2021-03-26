#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	int c;
	int add_new_line = FALSE;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			add_new_line = TRUE;
			continue;
		}
		if (add_new_line) {
			printf("\n");
			add_new_line = FALSE;
		}
		putchar(c);
	}
	return 0;
}
