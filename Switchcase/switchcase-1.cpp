#include<iostream>

using namespace std;

int main(void)
{
    int grade;

    cout << "Please input your grade : ";
    cin >> grade;

    switch(grade / 10)
    {
        case 10:
        case 9:
        case 8:
            cout << "A- ~ A+" << endl;
            break;
        case 7:
            cout << "B- ~ B+" << endl;
            break;
        case 6:
            cout << "C- ~ C+" << endl;
            break;
        default:
            cout << "F" << endl;
            break;
    }

    return 0;
}