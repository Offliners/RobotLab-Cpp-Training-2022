#include<iostream>
#include<string>
#include"func.h"

using namespace std;

int main(void)
{
    string n;
    std::getline(std::cin, n);

    GPA gpa(stoi(n));

    gpa.get_GPA();

    if(gpa.is_flunk_out())
        cout << "flunk out" << endl;

    return 0;
}