#ifndef _FUNC_H_
#define _FUNC_H_

#include<string>

class GPA
{
    public:
        GPA(int);
        void input_grade(std::string);
        double grade_table(const double) const;
        double get_GPA() const;
        bool is_flunk_out() const;
        ~GPA();

    private:
        int credit_ = 0;
        int credit_with_w_ = 0;
        double total_ = 0;
        int fail_credit_ = 0;
};

#endif