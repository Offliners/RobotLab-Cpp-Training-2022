#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>

class Bowling
{
    public:
        Bowling(std::string);
        ~Bowling();

    private:
        double reward_ = 40.;
};

#endif