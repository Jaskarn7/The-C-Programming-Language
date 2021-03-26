#include <stdio.h>

#define LIMIT 50

void get_line(char s[])
{
    int c, i = 0;
    while ((c = getchar()) != '\n') 
        s[i++] = c;
    s[i] = '\0'; 
}

int check_scientific_notation(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] == 'e')
            return 1;
    return 0;
}

double atof(char s[])
{
    double val;
    int power = 1, sign = 1;
    int i = 0;
    if (s[i] == '-') {
        sign = -1;
        ++i;
    }
    for (val = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
        val = 10.0 * val + (s[i] - '0');
    ++i;
    for (;s[i] != '\0'; ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int power_of_10(int p)
{
    int result = 1;
    while (p--) result *= 10;
    return result;
}

double scientific_notation(char s[])
{
    int sign = 1;
    int i = 0; 
    while (s[i++] != 'e') ;
    if (s[i] == '-') sign = -1;
    int power = 0;
    int temp = i - 1; // Pointing to e;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') 
            power = power * 10 + (s[i] - '0');
        ++i;
    }
    s[temp] = '\0';
    double d = atof(s);
    if (sign == 1) return d * power_of_10(power);
    return d / power_of_10(power); 
}

int main(void)
{
    char s[LIMIT];
    get_line(s);
    double d;
    if (check_scientific_notation(s)) 
        d = scientific_notation(s);
    else d = atof(s);
    printf("%.15lf\n", d);
    return 0;
}
