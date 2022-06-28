#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>
#include<vector>

class Vocab
{
    public:
        Vocab(std::string);
        void CSV_reader(const std::string);
        void search_vocab(std::string);
        std::string to_lower(std::string);
        ~Vocab();

    private:
        std::vector<std::string> english_meaning_;
        std::vector<std::string> chinese_meaning_;
};

#endif