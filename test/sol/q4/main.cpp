#include<iostream>
#include"func.h"

using namespace std;

int main(void)
{
    string record;
    std::getline(std::cin, record);

    Bowling bowling(record);

    bowling.get_score();
    bowling.get_reward();

    return 0;
}