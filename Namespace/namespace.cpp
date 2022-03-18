#include<iostream>

using namespace std;

namespace Me
{
    // If a > b, return 1 (true)
    int compare(int a, int b)
    {
        return a > b;
    }
}

namespace You
{
    // If a < b, return 1 (true)
    int compare(int a, int b)
    {
        return a < b;
    }
}

int main(void)
{
    int a = 10;
    int b = 20;

    cout << "Use My namespace : " << Me::compare(a, b) << endl;
    cout << "Use Your namespace : " << You::compare(a, b) << endl;

    return 0;
}