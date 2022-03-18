#include<iostream>
#include"func.h"

long long int factorial(int n)
{
    if(n > 1)
		return (n * factorial(n-1));
	else
		return 1;
}

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}

long long int power(int a,int b)
{
	if (b == 0)
		return 1;
	else
		return power(a, b - 1) * a;
}

void TOH(int n, char source, char target, char temp)
{
	if (n > 0)
	{
		TOH(n - 1, source, temp, target);
		std::cout << "\t" << source << " ==> "<< target << "\t\t" << n << std::endl;
		TOH(n - 1, temp, target, source);
	}
}