#include<iostream>
#include"func.h"

using namespace std;

int main(void)
{
    int n;

    cin >> n;
    cin.get();
    GPA gpa(n);

    cout << gpa.get_GPA() << endl;

    if(gpa.is_flunk_out())
        cout << "flunk out" << endl;

    return 0;
}