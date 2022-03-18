#include<iostream>

using namespace std;

int main(void)
{
    int i = 1;
    int sum = 0;

    while(i <= 100)
    {
        sum += i;
        ++i;
    }
    
    cout << "Result of adding 1 to 100 = " << sum << endl;
    cout << "The last i = " << i << endl;

    return 0;
}