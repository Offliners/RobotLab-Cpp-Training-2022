#include<iostream>

using namespace std;

int main(void)
{
    int grade;

    cout << "Please tell your grade to your Mom : ";
    cin >> grade;

    if(80 <= grade <= 100)
        cout << "You get A- ~ A+, Great!" << endl;
    else
        cout << "Who are you? You're not my child." << endl;

    if(80 <= grade && grade <= 100)
        cout << "You get A- ~ A+, Great!" << endl;
    else
        cout << "Who are you? You're not my child." << endl;
        
    return 0;
}