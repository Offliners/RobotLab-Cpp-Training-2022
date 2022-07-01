#include<iostream>
#include<algorithm>
#include"func.h"

SimpleCalculator::SimpleCalculator(std::string expr)
{
    expr_ = expr;
}


void SimpleCalculator::print_result() const
{
    std::cout << result_ << std::endl;
}


bool SimpleCalculator::is_digit(const char c) const
{
    return (c >= '0' && c <= '9');
}


void SimpleCalculator::calculate()
{
    int i = 0;
	int index = 1;
    std::string postfix = "_";
	while(expr_[i] != '\0')
	{
		char token = expr_[i];

		if(token != '=')
		{
			if(is_digit(token))
			{
				postfix.push_back(token);
				++index;
			}
			else if(token == '(')
				operator_stack.push(token);
			else if(token == ')')
			{
				while(operator_stack.top() != '(')
				{
					postfix.push_back(operator_stack.top());
                    operator_stack.pop();
					++index;
				}

				operator_stack.pop();
			}
			else
			{
				while(is_precedence(token))
				{
					postfix.push_back(operator_stack.top());
                    operator_stack.pop();
					++index;
				}

				postfix.push_back('_');
				++index;
				operator_stack.push(token);
			}
		}
		else
		{
			while(!operator_stack.empty())
			{
				postfix.push_back(operator_stack.top());
                operator_stack.pop();
				++index;
			}

            eval(postfix, index);
			print_result();

            while(!operator_stack.empty())
                operator_stack.pop();
		}

		++i;
	}
}


bool SimpleCalculator::is_precedence(char token)
{
    if(operator_stack.empty())
        return false;

    char top_token = operator_stack.top();
    if(((top_token == '*') || (top_token == '/') || (top_token == '%')) || (((top_token == '+') || (top_token == '-')) && ((token == '+') || (token == '-'))))
		return true;
	else
		return false;
}


void SimpleCalculator::eval(std::string postfix, int index)
{
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

			operand_stack.push(num);
		}
		else
		{
			LLI b = operand_stack.top();
            operand_stack.pop();
			LLI a = operand_stack.top();
            operand_stack.pop();
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
					result = down_floor((LD)a / b);
					break;
				case '%':
					result = a % b;
					break;
				default:
                    break;
			}

			operand_stack.push(result);
			++i;
		}
    }

	result_ = operand_stack.top();
    operand_stack.pop();
}


LLI SimpleCalculator::down_floor(LD num)
{
	if(num < 0)
        return (LLI)(num - 1);
    else
        return (LLI)num;
}

SimpleCalculator::~SimpleCalculator() {};