#include<iostream>

using namespace std;

int main(void)
{
    int grade;

    cout << "Please input your grade : ";
    cin >> grade;

    switch(grade)
    {
        case 80 ... 100:
            cout << "A- ~ A+" << endl;
            break;
        case 70 ... 79:
            cout << "B- ~ B+" << endl;
            break;
        case 60 ... 69:
            cout << "C- ~ C+" << endl;
            break;
        default:
            cout << "F" << endl;
            break;
    }

    return 0;
}