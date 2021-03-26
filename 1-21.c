#include <stdio.h>

#define TABSTOP 8

int check_tabs(int blanks, int pos, int k)
{
	if (k % TABSTOP == 0) ++k;
	while (k % TABSTOP != 0) ++k;
	return (k <= (blanks+pos));
}

int do_tabs(int blanks, int k) 
{
	if (k % TABSTOP == 0) ++k;
	while (k % TABSTOP != 0) ++k;
	return k;
}


int entab(int blanks, int pos) 
{
	int k = pos;
	int t = 0, b = 0;
	while (k < (blanks+pos)) {
		if (check_tabs(blanks, pos, k)) {
			putchar('\t');
			++t;
			k = do_tabs(blanks, k);
		}
		else {
			b++;
			putchar(' ');
			++k;
		}
	}
	return k;
}

int main(void) 
{
	int pos = 0, blanks = 0, c;
	while ((c = getchar()) != '\n') {
		if (c == ' ') ++blanks;
		else {
			if (blanks > 0) {
				pos = entab(blanks, pos);
				blanks = 0;	
			}
			putchar(c);
			++pos;
		}
	}
}
