#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>
#include<vector>

class Vocab
{
    public:
        Vocab(int, std::string);
        void CSV_reader();
        ~Vocab();

    private:
        int num_word_ = 0;
        std::string csv_path_ = "";
};

#endif