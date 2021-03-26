#include <stdio.h>

#define MAXWORDS 20

#define YES 1
#define NO 0

int main(void) 
{
	int break_now = NO, w = 0, c;
	while((c = getchar()) != '\n') {
		if (c == ' ') ++w;
		if (w >= MAXWORDS) break_now = YES;
		if (break_now && c == ' ') {
			putchar('\n');
			break_now = NO;
			w = 0;
		}
		else putchar(c);
	}
	return 0;
}
