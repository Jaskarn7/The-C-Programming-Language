#include <stdio.h>
#include <ctype.h>

void uppr()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));
}

void lowr()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(toupper(c));
}

int main(int argc, char *argv[])
{
	int cond = 0;
	if (isupper(*(argv[0] += 2)))
		cond = 1;
	if (cond)
		uppr();
	else
		lowr();
	return 0;
}
