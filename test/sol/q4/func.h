#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>

class Bowling
{
    public:
        Bowling(std::string);
        void get_score() const;
        void get_reward() const;
        ~Bowling();

    private:
        double reward_ = 40.;
        int num_spare_ = 0;
        int num_strike_ = 0;
};

#endif