#include<iostream>

using namespace std;

int main(void)
{
    int i = 4;
    int j = 3;

    cout << "4 / 3 = " << i / j << endl;
    cout << endl;

    // implicit conversion
    cout << "4 / (double)3 = " << i / (double)j << endl;
    cout << "(double)4 / 3 = " << (double)i / j << endl;
    cout << "(double)4 / (double)3 = " << (double)i / (double)j << endl;
    cout << endl;

    // explicit cast
    cout << "4 / (double)3 = " << i / 3.0 << endl;
    cout << "(double)4 / 3 = " << 4.0 / j << endl;
    cout << endl;

    return 0;
}