#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
    int arr[4];
    int tab[3][2];

    for(int i = 0; i < 4; ++i)
        arr[i] = i;

    int count = 4;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            tab[i][j] = count;
            ++count;
        }
    }

    int *p = arr + 1;
    int *mp[2] = {arr, tab[2]};
    int **pp = &p;
    int **qq = mp;
    int (*s)[2] = tab;

    // Variable table (Datatype : int)
    cout << setw(8) << "Value" << "   " << "Variable" << endl;
    for(int i = 0; i < 10; ++i)
        cout << setw(6) << i << " " << setw(8) << char(65 + i) << endl;
    cout << endl;

    // Address table (Datatype : int*)
    cout << setw(10) << "Value" << "         " << "Address" << endl;
    for(int i = 0; i < 5; ++i)
        cout << setw(6) << (arr + i) << " " << setw(8) << char(97 + i) << endl;

    count = 0;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            cout << setw(6) << &tab[i][j] << " " << setw(8) << char(97 + count + 5) << endl;
            ++count;
        }
    }
    cout << setw(6) << tab + 3 << " " << setw(8) << char(97 + count + 5) << endl << endl;

    cout << setw(13) << "Expression" << setw(14) << "Answer" << endl;
    cout << setw(12) << "tab[1]+1" << setw(20) << tab[1] + 1 << endl;
    cout << setw(12) << "tab[1][1]" << setw(20) << tab[1][1] << endl;
    cout << setw(12) << "&tab[1][1]" << setw(20) << &tab[1][1] << endl;
    cout << setw(12) << "&tab[1][1]+1" << setw(20) << &tab[1][1] + 1 << endl;
    cout << setw(12) << "p+0" << setw(20) << p + 0 << endl;
    cout << setw(12) << "p+1" << setw(20) << p + 1 << endl;
    cout << setw(12) << "*p" << setw(20) << *p << endl;
    cout << setw(12) << "p[2]" << setw(20) << p[2] << endl;
    cout << setw(12) << "mp[0][1]" << setw(20) << mp[0][1] << endl;
    cout << setw(12) << "mp[1][1]" << setw(20) << mp[1][1] << endl;
    cout << setw(12) << "*pp+2" << setw(20) << *pp + 2 << endl;
    cout << setw(12) << "qq[1]" << setw(20) << qq[1] << endl;
    cout << setw(12) << "qq[1]+1" << setw(20) << qq[1] + 1 << endl;
    cout << setw(12) << "qq[0][0]" << setw(20) << qq[0][0] << endl;
    cout << setw(12) << "qq[1][0]" << setw(20) << qq[1][0] << endl;
    cout << setw(12) << "s[0][1]" << setw(20) << s[0][1] << endl;
    cout << setw(12) << "s[1][0]" << setw(20) << s[1][0] << endl;

    return 0;
}