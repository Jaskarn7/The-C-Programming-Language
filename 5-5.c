void str_cpy(char *s, char *t, int n)
{
    while (*s != '\0')
        ++s;
    while (n-- && *t != '\0')
        *s++ = *t++;
    *s = '\0';
}
