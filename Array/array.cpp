#include<iostream>

#define ARRSIZE 3

using namespace std;

int main(void)
{
    int a[ARRSIZE];

    cout << "Array declaration with \"int a[3];\"" << endl;
    for(int i = 0; i < ARRSIZE; ++i)
        cout << a[i] << " ";
    
    cout << endl;

    int b[ARRSIZE] = {1, 2, 3};
    cout << "Array declaration with \"int b[3] = {1, 2, 3};\"" << endl;
    for(int i = 0; i < ARRSIZE; ++i)
        cout << b[i] << " ";
    
    cout << endl;

    int c[ARRSIZE] = {};
    cout << "Array declaration with \"int c[3] = {};\"" << endl;
    for(int i = 0; i < ARRSIZE; ++i)
        cout << c[i] << " ";
    
    cout << endl;

    int d[ARRSIZE] = {1};
    cout << "Array declaration with \"int d[3] = {1};\"" << endl;
    for(int i = 0; i < ARRSIZE; ++i)
        cout << d[i] << " ";
    
    cout << endl;

    return 0;
}