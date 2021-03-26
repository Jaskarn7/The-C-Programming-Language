int str_end(char *s, char *t)
{
	char *b_s = s; // Beggining of string s
	char *b_t = t; // Beggining of string t
	while (*s != '\0')
		++s; 		/* Go to end of string s */
	while (*t != '\0')
		++t;		/* Go to end of string t */
	while (t >= b_t) {
		if (s < b_s || *s != *t) return 0;
		--s;
		--t;
	}
	return 1;
}
