#include <stdio.h>

#define MAXOP 100
#define NUMBER '0'
#define PRINTTOP '^'
#define DUPLICATETOP '$'
#define SWAPTOPELEMENTS '@'
#define CLEARSTACK '!'

int buf[MAXOP];
int bufp = 0;
int stack[MAXOP];
int stack_size = 0;

int is_digit(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int get_ch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(int n)
{
    if (bufp == MAXOP) printf("unget_ch: Too many operands\n");
    else buf[bufp++] = n;
}

int get_op(char s[])
{
    int i = 0, c, d;
    while ((s[0] = c = get_ch()) == ' ' || c == '\t') ;
    if (c == '-') {
        i = 0;
        d = getchar();
        if (is_digit(d)) {
            s[++i] = d;
            while (is_digit(s[++i] = c = get_ch())) ;
            s[i] = '\0';
            if (c != EOF) unget_ch(c);
            return NUMBER;
        }
        else
            buf[bufp] = d;
    }
    s[1] = '\0';
    if (!is_digit(c)) return c; // Not a number
    i = 0;
    while (is_digit(s[++i] = c = get_ch())) ;
    s[i] = '\0';
    if (c != EOF) unget_ch(c);
    return NUMBER;
}

int atoi(char s[])
{
    int val = 0, i = 0, sign = 1;
    if (s[i] == '-') {
        sign = -1;
        ++i;
    }
    while (s[i] != '\0')
        val = val * 10 + (s[i++] - '0');
    return sign * val;
}

void push(int n)
{
    if (stack_size == MAXOP)
        printf("\nError: Stack is full\n");
    else
        stack[stack_size++] = n;
}

int pop()
{
    if (stack_size == 0) {
        printf("\nError: Stack is empty\n");
        return -1;
    }
    return stack[--stack_size];
}

void print_arr(char s[])
{
    printf("Inside the array s: ");
    for (int i=0; s[i] != '\0'; ++i)
        printf("%c ", s[i]);
    printf("\n");
}

void print_top()
{
    printf("Top of stack is: %d\n", stack[stack_size-1]);
}

void duplicate_top()
{
    push(stack[stack_size-1]);
}

void swap_top_elements()
{
    int op1 = pop();
    int op2 = pop();
    push(op1);
    push(op2);
}

void clear_stack()
{
    stack_size = 0;
}

int main(void)
{
    char s[MAXOP];
    int type, op1;
    while ((type = get_op(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atoi(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op1 = pop();
                push(pop() - op1);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op1 = pop();
                push(pop() / op1);
                break;
            case '%':
                op1 = pop();
                push(pop() % op1);
                break;
            case PRINTTOP:
                print_top();
                break;
            case DUPLICATETOP:
                duplicate_top();
                break;
            case SWAPTOPELEMENTS:
                swap_top_elements();
                break;
            case CLEARSTACK:
                clear_stack();
                break;
            case '\n':
                printf("\nThe result is: %d\n", pop());
                break;
            default:
                break;
        }
    }
}
