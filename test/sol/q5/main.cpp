#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 101
#define MAXLENGTH 1000001

typedef long long int LLI;
typedef long double LD;

typedef struct stack_for_converting_infix_to_postfix
{
	int top;
	int capacity;
	char *operators;
} operator_stack;

void operator_stack_init(operator_stack *s);
int is_operator_empty_stack(operator_stack *s);
int is_operator_full_stack(operator_stack *s);
void operator_stack_push(operator_stack *s, char new_operator);
char operator_stack_pop(operator_stack *s);
char operator_stack_top(operator_stack *s);

typedef struct stack_for_calculating_result
{
	int top;
	int capacity;
	LLI *operand;
} operand_stack;

void operand_stack_init(operand_stack *s);
int is_operand_empty_stack(operand_stack *s);
int is_operand_full_stack(operand_stack *s);
void operand_stack_push(operand_stack *s, LLI new_operand);
LLI operand_stack_pop(operand_stack *s);
LLI operand_stack_top(operand_stack *s);

int is_digit(char c);
int is_precedence(char top_token, char token);
LLI eval(char *postfix, int index);
LLI down_floor(LD num);

int main(void)
{
	char *expr = (char*)malloc(MAXLENGTH * sizeof(char));
	char *postfix = (char*)malloc(MAXLENGTH * sizeof(char));

	postfix[0] = '_';
	operator_stack operator_s;
	operator_stack_init(&operator_s);

	if(!scanf("%s", expr))
		printf("Error!\n");

	int i = 0;
	int index = 1;
	while(expr[i] != '\0')
	{
		char token = expr[i];

		if(token != '=')
		{
			if(is_digit(token))
			{
				postfix[index] = token;
				++index;
			}
			else if(token == '(')
				operator_stack_push(&operator_s, token);
			else if(token == ')')
			{
				while(operator_stack_top(&operator_s) != '(')
				{
					postfix[index] = operator_stack_pop(&operator_s);
					++index;
				}

				operator_stack_pop(&operator_s);
			}
			else
			{
				while(is_precedence(operator_stack_top(&operator_s), token))
				{
					postfix[index] = operator_stack_pop(&operator_s);
					++index;
				}

				postfix[index] = '_';
				++index;
				operator_stack_push(&operator_s, token);
			}
		}
		else
		{
			while(!is_operator_empty_stack(&operator_s))
			{
				postfix[index] = operator_stack_pop(&operator_s);
				++index;
			}

			// for(int j = 0; postfix[j] != '\0'; ++j)
			// 	printf("%c", postfix[j]);
			// printf("\n");

			LLI result = eval(postfix, index);
			printf("Print: %lld\n", result);

			memset(postfix, 0, index);

			int count = 0;
			int sign = (result < 0) ? -1 : 1; 
			int flag = (result < 0) ? 1 : 0;

			for(int j = 0; result != 0; ++j)
			{
				char temp =  ((sign * result) % 10 + '0');

				if(flag)
				{
					postfix[j] = '-';
					++j;
					++count;
					flag = 0;
				}

				postfix[j] = temp;
				result = result / 10;
				++count;
			}

			postfix[count] = '_';

			for(int j = 0; j < strlen(postfix) / 2; ++j)
			{  
				char temp = postfix[j];  
				postfix[j] = postfix[strlen(postfix) - j - 1];  
				postfix[strlen(postfix) - j - 1] = temp;  
			}

			index = (1 + count);
			operator_s.top = -1; 
		}

		++i;
	}

	free(expr);
	free(postfix);

	return 0;
}

void operator_stack_init(operator_stack *s)
{
	s->top = -1;
	s->capacity = MAXSIZE;
	s->operators = (char*)malloc(MAXLENGTH * sizeof(char));
}

int is_operator_empty_stack(operator_stack *s)
{
	return (s->top < 0);
}

int is_operator_full_stack(operator_stack *s)
{
	return (s->top == MAXSIZE - 1);
}

void operator_stack_push(operator_stack *s, char new_operator)
{
	s->operators[s->top] = new_operator;
	s->top++;
}

char operator_stack_pop(operator_stack *s)
{
	s->top--;
	return (s->operators[s->top]);
}

char operator_stack_top(operator_stack *s)
{
	return (s->operators[s->top - 1]);
}

void operand_stack_init(operand_stack *s)
{
	s->top = -1;
	s->capacity = MAXSIZE;
	s->operand = (LLI*)malloc(MAXLENGTH * sizeof(LLI));
}

int is_operand_empty_stack(operand_stack *s)
{
	return (s->top < 0);
}

int is_operand_full_stack(operand_stack *s)
{
	return (s->top == MAXSIZE - 1);
}

void operand_stack_push(operand_stack *s, LLI new_operand)
{
	s->operand[s->top] = new_operand;
	s->top++;
}

LLI operand_stack_pop(operand_stack *s)
{
	s->top--;
	return (s->operand[s->top]);
}

LLI operand_stack_top(operand_stack *s)
{
	return (s->operand[s->top - 1]);
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_precedence(char top_token, char token)
{
	if(((top_token == '*') || (top_token == '/') || (top_token == '%')) || (((top_token == '+') || (top_token == '-')) && ((token == '+') || (token == '-'))))
		return 1;
	else
		return 0;
}

LLI eval(char *postfix, int index)
{
	operand_stack operand_s;
	operand_stack_init(&operand_s);

    int i = 0;
    while(i < index)
    {
		char token = postfix[i];
		if(token == '_')
		{
			++i;
			token = postfix[i];
			LLI num = 0;

			while(is_digit(token))
			{
				num = num * 10 + (token - '0');

				++i;
				token = postfix[i];
			}

			operand_stack_push(&operand_s, num);
		}
		else
		{
			LLI b = operand_stack_pop(&operand_s);
			LLI a = operand_stack_pop(&operand_s);
			LLI result;

			switch(token)
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					result = down_floor((long double)a / b);
					break;
				case '%':
					result = a % b;
					break;
				default:
					printf("%c is unknown operator!\n", token);
					exit(1);
			}
			// printf("Porcess : %lld %c %lld = %lld\n", a, token, b, result);

			operand_stack_push(&operand_s, result);
			++i;
		}
    }

	return operand_stack_pop(&operand_s);
}

LLI down_floor(LD num)
{
	if(num < 0)
        return (LLI)(num - 1);
    else
        return (LLI)num;
}