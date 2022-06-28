#include<iostream>
#include"func.h"

using namespace std;

int main(void)
{
    int n;

    cin >> n;
    cin.get();
    string vocab_csv = "./q2/7000.csv";
    Vocab vocab(vocab_csv);

    string word;
    for(int i = 0; i < n; ++i)
    {
        cin >> word;
        cin.get();
        vocab.search_vocab(word);
    }

    return 0;
}