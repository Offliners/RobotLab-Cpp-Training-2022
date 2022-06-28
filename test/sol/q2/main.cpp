#include<iostream>
#include"func.h"

using namespace std;

int main(void)
{
    int n;

    cin >> n;
    cin.get();
    string vocab_csv = "./q2/7000.csv";
    Vocab vocab(n, vocab_csv);


    return 0;
}