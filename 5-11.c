#include <stdio.h>

#define DEFAULT_TAB_STOP 8

int TABSTOP = DEFAULT_TAB_STOP;

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

int conv_to_int(char *p)
{
    int n = 0;
    while (*p != '\0')
        n = n*10 + (*p++ - '0');
    return n;
}

int main(int argc, char *argv[])
{
    for (int i=1; i < argc; ++i) {
        if (argv[i] == "-t") {
            TABSTOP = conv_to_int(argv[i+1]);
        }
    }
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
