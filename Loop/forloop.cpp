#include<iostream>

using namespace std;

int main(void)
{
    int i;
    int sum = 0;

    for(i = 1; i <= 100; ++i)
        sum += i;
    
    cout << "Result of adding 1 to 100 = " << sum << endl;
    cout << "The last i = " << i << endl;

    return 0;
}