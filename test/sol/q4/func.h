#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>
#include<vector>

class Bowling
{
    public:
        Bowling(std::string);
        void calculate_score(std::vector<std::string>);
        void get_score() const;
        void get_reward() const;
        int convert(const std::vector<std::string>, const int);
        ~Bowling();

    private:
        int score_ = 0;
        double reward_ = 40.;
        int num_spare_ = 0;
        int num_strike_ = 0;
};

#endif