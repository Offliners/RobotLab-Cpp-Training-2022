#include<iostream>

using namespace std;

int main(void)
{
    int num1 = 10, num2 = 20,
    *ptr11, *ptr12,
    **ptr2;

    ptr11 = &num1;
    ptr12 = &num2;
    ptr2 = &ptr11;

    *ptr11 = 30;    // 1
    *ptr2 = &num2;  // 2
    *ptr11 = 40;    // 3
    *ptr12 = 50;    // 4
    **ptr2 = 60;    // 5

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    return 0;
}