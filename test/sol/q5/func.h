#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>
#include<stack>

typedef long long int LLI;
typedef long double LD;

class SimpleCalculator
{
    public:
        SimpleCalculator(std::string);
        void print_result() const;
        bool is_digit(const char) const;
        void calculate();
        bool is_precedence(char);
        void eval(std::string, int);
        LLI down_floor(LD);
        ~SimpleCalculator();

    private:
        LLI result_ = 0;
        std::string expr_ = "";
        std::stack<char> operator_stack;
        std::stack<LLI> operand_stack;
};

#endif