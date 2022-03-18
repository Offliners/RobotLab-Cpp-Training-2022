#include<iostream>
#include<limits>

using namespace std;

int main(void)
{
    int int_max = numeric_limits<int>::max();
    int int_min = numeric_limits<int>::min();
    bool bool_max = numeric_limits<bool>::max();
    bool bool_min = numeric_limits<bool>::min();
    float float_max = numeric_limits<float>::max();
    float float_min = numeric_limits<float>::min();
    double double_max = numeric_limits<double>::max();
    double double_min = numeric_limits<double>::min();    
    long long longlong_max = numeric_limits<long long>::max();
    long long longlong_min = numeric_limits<long long>::min();	
    char char_max = numeric_limits<char>::max();
    char char_min = numeric_limits<char>::min();

    cout << "============================" << endl;
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "bool is " << sizeof(bool) << " bytes." << endl;
    cout << "float is " << sizeof(float) << " bytes." << endl;
    cout << "double is " << sizeof(double) << " bytes." << endl;
    cout << "long long is " << sizeof(long long) << " bytes." << endl;
    cout << "char is " << sizeof(char) << " bytes." << endl;
    cout << endl;

    cout << "============================" << endl;
    cout << "Maximum values:" << endl;
    cout << "int: " << int_max << endl;
    cout << "bool: " << bool_max << endl;
    cout << "float: " << float_max << endl;
    cout << "double: " << double_max << endl;
    cout << "long long: " << longlong_max << endl;
    cout << "char: " << int(char_max) << endl;  // Convert char_max to integer because we want to know its value 
    cout << endl;

    cout << "============================" << endl;
    cout << "Minimum values:" << endl;
    cout << "int: " << int_min << endl;
    cout << "bool: " << bool_min << endl;
    cout << "float: " << float_min << endl;
    cout << "double: " << double_min << endl;
    cout << "long long: " << longlong_min << endl;
    cout << "char: " << int(char_min) << endl;
    cout << endl;

    return 0;
}