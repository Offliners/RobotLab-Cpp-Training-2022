#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cctype>
#include"func.h"

Vocab::Vocab(std::string path)
{
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
            {
                word = to_lower(word);
                english_meaning_.push_back(word);
            }
            else
                chinese_meaning_.push_back(word);
        }
    }

    fin.close();
}

void Vocab::search_vocab(std::string word)
{
    word = to_lower(word);
    std::vector<std::string>::iterator it = std::find(english_meaning_.begin(), english_meaning_.end(), word);

    if(it != english_meaning_.end())
    {
        char delimiter = '.';
        int index = std::distance(english_meaning_.begin(), it);

        std::string meaning = chinese_meaning_[index];
        int found = meaning.rfind(delimiter) + 1;
        meaning.insert(found, " ");

        std::cout << meaning << std::endl;
    }
    else
        std::cout << "Unknown" << std::endl;
}

std::string Vocab::to_lower(std::string word)
{
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

    return word;
}

Vocab::~Vocab() {};