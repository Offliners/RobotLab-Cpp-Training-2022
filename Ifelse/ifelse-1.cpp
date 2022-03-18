#include<iostream>

using namespace std;

int main(void)
{
    int grade;

    cout << "Please tell your grade to your Mom : ";
    cin >> grade;

    if(grade >= 90)
        cout << "You get A+, Great!" << endl;
    else if(grade >= 84)
        cout << "You get A, Good!" << endl;
    else if(grade >= 80)
        cout << "You get A-, Not bad!" << endl;
    else
        cout << "Who are you? You're not my child." << endl;
        
    return 0;
}