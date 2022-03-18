#include<iostream>

using namespace std;

int main(void)
{
    int i = 1;
    int sum = 0;

    do
    {
        sum += i;
        ++i;
    } while(i <= 100);
    
    cout << "Result of adding 1 to 100 = " << sum << endl;
    cout << "The last i = " << i << endl;

    return 0;
}