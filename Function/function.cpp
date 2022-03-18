#include<iostream>

using namespace std;

long long int factorial(int);

int main(void)
{
    int n;

    cout << "Please input an integer : ";
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;

    return 0;
}

long long int factorial(int n)
{
    if(n > 1)
		return (n * factorial(n-1));
	else
		return 1;
}