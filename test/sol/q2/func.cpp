#include<iostream>
#include<string>
#include <fstream>
#include"func.h"

Vocab::Vocab(int n, std::string path)
{
    num_word_ = n;
    csv_path_ = path;


}

Vocab::~Vocab() {};