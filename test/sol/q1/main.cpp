#include<iostream>
#include<string>
#include"func.h"

using namespace std;

int main(void)
{
    string n;
    std::getline(std::cin, n);

    GPA gpa(stoi(n));

    cout << gpa.get_GPA() << endl;

    if(gpa.is_flunk_out())
        cout << "flunk out" << endl;

    return 0;
}