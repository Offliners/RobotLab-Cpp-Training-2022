#include<iostream>

using namespace std;

int main(void)
{
    int x, y, z;
    x = 1;
    y = 2;
    z = 3;
    x = y = z;
    cout << "x = y = z" << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << endl;

    x = 1;
    y = 2;
    z = 3;
    x = (y = z);
    cout << "x = (y = z)" << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << endl;

    x = 1;
    y = 2;
    z = 3;
    (x = y) = z;
    cout << "(x = y) = z" << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << endl;


    return 0;
}