void str_cat(char *s, char *t)
{
    while (*s != '\0') s++; /* Moves to end of string s.*/
    while (*t != '\0') *s++ = *t++; /* Copies t to s*/
}
