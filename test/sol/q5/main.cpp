#include<iostream>
#include<string>
#include"func.h"

using namespace std;

int main(void)
{
	string expr;
	getline(cin, expr);

	SimpleCalculator calc(expr);
	calc.calculate();

	return 0;
}