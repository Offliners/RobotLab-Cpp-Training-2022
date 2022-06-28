#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"func.h"

Bowling::Bowling(std::string record)
{
    int rounds = 0;
    std::vector<std::string> records;
    for(int i = 0; i < record.length(); ++i)
    {
        if(record[i] == ' ')
            continue;
        else if(record[i] <= '9' && record[i] >= '0' || record[i] == 'x' || record[i] == '/')
        {
            std::string s(1, record[i]);
            records.push_back(s);
        }

        ++rounds;
    }

    if(rounds < 21)
        for(int i = 0; i < 21 - rounds; ++i)
            records.push_back("0"); 

    calculate_score(records);
}

void Bowling::calculate_score(std::vector<std::string> records)
{
    for(int i = 0; i < records.size(); ++i)
    {
        if(records[i] == "x")
        {
            ++num_strike_;
            score_ += 10;

            if(i < records.size() - 2)
                score_ += convert(records, i + 1);
            
            if(i < records.size() - 2)
                score_ += convert(records, i + 2);
        }
        else if(records[i] == "/")
        {
            ++num_spare_;
            score_ += convert(records, i);

            if(i < records.size() - 2)
                score_ += convert(records, i + 1);
        }
        else
            score_ += convert(records, i);
    }
}

void Bowling::get_score() const
{
    std::cout << score_ << std::endl;
}

void Bowling::get_reward() const
{
    double total_reward = reward_ * std::pow(1.1, num_spare_) * std::pow(1.2, num_strike_);
    std::cout << std::round(total_reward) << std::endl;
}

int Bowling::convert(const std::vector<std::string> records, const int index)
{
    int score;
    if(records[index] == "x")
        score = 10;
    else if(records[index] == "/")
        score = 10 - std::stoi(records[index-1]);
    else
        score = std::stoi(records[index]);
    
    return score;
}

Bowling::~Bowling() {};