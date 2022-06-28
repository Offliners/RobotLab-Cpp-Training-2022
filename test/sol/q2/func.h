#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>
#include<vector>

class Vocab
{
    public:
        Vocab(int, std::string);
        void CSV_reader(const std::string);
        ~Vocab();

    private:
        int num_word_ = 0;
        std::vector<std::string> english_meaning;
        std::vector<std::string> chinese_meaning;
};

#endif