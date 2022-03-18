#include<iostream>

using namespace std;

int GCD(int, int);

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        cout << "Please use command " << argv[0] <<" [integer1] [integer2]" << endl;
        exit(1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    cout << "gcd(" << a << ", " << b << ") = " << GCD(a, b) << endl;
}

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}