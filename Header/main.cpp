#include<iostream>
#include"func.h"

using namespace std;

int main(void)
{
    int n;

    cout << "Enter number of plates : ";
    cin >> n;

    cout << "\tmove method\tdisk number" << endl;
    TOH(n, 'A', 'B', 'C');

    return 0;
}