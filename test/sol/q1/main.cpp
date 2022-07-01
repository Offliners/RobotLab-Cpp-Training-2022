#include<iostream>
#include<string>
#include"func.h"

using namespace std;

int main(void)
{
    string n;
    getline(cin, n);

    GPA gpa(stoi(n));

    gpa.get_GPA();

    if(gpa.is_flunk_out())
        cout << "flunk out" << endl;

    return 0;
}