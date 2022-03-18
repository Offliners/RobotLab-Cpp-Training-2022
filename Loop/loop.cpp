#include<iostream>

using namespace std;

int main(void)
{
    int i = 0;

    cout << "while test" << endl;
    while(i > 0 && i < 10)
    {
        cout << i << " ";
        ++i;
    }
    cout << endl;

    cout << "do while test" << endl;
    do
    {
        cout << i << " ";
        ++i;
    } while(i > 0 && i < 10);
    cout << endl;

    
    return 0;
}