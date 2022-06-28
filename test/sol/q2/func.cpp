#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"func.h"

Vocab::Vocab(int n, std::string path)
{
    num_word_ = n;
    CSV_reader(path);
}

void Vocab::CSV_reader(const std::string path)
{
    std::ifstream fin(path);
    char delimiter = ',';
    for(std::string line; std::getline(fin, line);)
    {
        std::istringstream in(line);

        int i = 0;
        for(std::string word; std::getline(in, word, delimiter); ++i)
        {
            if(i == 0)
                english_meaning.push_back(word);
            else
                chinese_meaning.push_back(word);
        }
    }

    fin.close();

    for(int i = 0; i < english_meaning.size(); ++i) // values.size()
    {
        std::cout << chinese_meaning[i] << std::endl;
    }
}

Vocab::~Vocab() {};