#include <stdio.h>

#define MAXOP 1000

int stack[MAXOP];
int stack_size = 0;

void push_num(int n)
{
	stack[stack_size++] = n;
}

int pop(void)
{
	return stack[--stack_size];
}

void operand_found(char *p)
{
	int op1 = pop();
	int op2 = pop();
	switch (*p) {
		case '+':
			push_num(op1+op2);
			break;
		case '-':
			push_num(-1*op2 + op1);
			break;
		case '*':
			push_num(op1 * op2);
			break;
		case '/':
			push_num(op2 / op1);
			break;
		default:

			break;
	}
}

int conv_to_int(char *p)
{
	int n = 0;
	while (*p != '\0')
		n = n * 10 + (*p++ - '0');
	return n;
}

int is_digit(char *p)
{
	return (*p >= '0' && *p <= '9');
}

int is_operand(char *p)
{
	char operands[] = {'+', '-', '*', '/'};
	for (int i = 0; i < (sizeof(operands)/sizeof(operands[0])); ++i)
		if (*p == operands[i])
			return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	for (int i=1; i < argc; ++i) {
		if (is_digit(argv[i]))
			push_num(conv_to_int(argv[i]));
		else if (is_operand(argv[i]))
			operand_found(argv[i]);
		else {
			printf("Unknown character entered at: %s\n", argv[i]);
			return 0;
		}
	}
	printf("The result is: %d\n", pop());
	return 0;
}
