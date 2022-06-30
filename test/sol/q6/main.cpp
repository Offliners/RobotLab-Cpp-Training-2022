#include<iostream>
#include<string>
#include"func.h"

using namespace std;

int main(void)
{
    int M, N, K;
    cin >> M >> N >> K;
    cin.get();

    McDonalds mc(M, K);
    string situation;
    for(int i = 0; i < N; ++i)
    {
        cin >> situation;

        switch(situation[0])
        {
            case 'e':
                break;
            case 'g':
                break;
            case 'l':
                break;
            case 'c':
                break;
            default:
                cout << "Unknown Situation!" << endl;
                break;
        }
    }

    return 0;
}