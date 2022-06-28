#include<iostream>
#include<string>
#include<cmath>
#include"func.h"

GPA::GPA(int n)
{
    std::string input_data;
    for(int i = 0; i < n; ++i)
    {
        std::getline(std::cin, input_data);
        input_grade(input_data);
    }
}

void GPA::input_grade(std::string input_data)
{
    int pos = 0;
    for(int i = 0; i < input_data.length(); ++i)
    {
        if(input_data[i] == ' ')
        {
            pos = i;
            break;
        }
    }

    double grade;
    if(input_data.substr(0, pos) == "F")
        grade = 0.0;
    else if(input_data.substr(0, pos) == "W")
        grade = -1.0;
    else
        grade = (pos == 0 ? 0 : std::stod(input_data.substr(0, pos)));

    int credit = (pos == 0 ? 0 : std::stoi(input_data.substr(pos + 1, input_data.length())));

    credit_with_w_ += credit;
    grade = grade_table(grade);
    if(grade >= 0)
    {
        credit_ += credit;
        total_ += grade * credit;
    }

    if(grade == 0)
        fail_credit_ += credit;
}

double GPA::grade_table(const double grade) const
{
    int score = std::round(grade);
    switch(score)
    {
        case 90 ... 100:
            return 4.3;
        case 85 ... 89:
            return 4;
        case 80 ... 84:
            return 3.7;
        case 77 ... 79:
            return 3.3;
        case 73 ... 76:
            return 3;
        case 70 ... 72:
            return 2.7;
        case 67 ... 69:
            return 2.3;
        case 63 ... 66:
            return 2;
        case 60 ... 62:
            return 1.7;
        case 0 ... 59:
            return 0;
        default:
            return -1;
    } 
}

double GPA::get_GPA() const
{
    if(credit_ == 0)
        return 0;

    int gpa_round = std::round(100 * total_ / credit_);
    return gpa_round / 100 + (gpa_round % 100) / 100.0;
}

bool GPA::is_flunk_out() const
{
    if(fail_credit_ > (credit_with_w_ / 2))
        return true;
    else
        return false;
}

GPA::~GPA() {};