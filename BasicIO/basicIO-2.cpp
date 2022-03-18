#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
    // setbase
    int n = 127;

    cout << n << endl;
    cout << "bin (base =  2): " << setbase(2) << n << endl; // It doesn't work because the standard says no
    cout << "oct (base =  8): " << setbase(8) << n << endl;
    cout << "dec (base = 10): " << setbase(10) << n << endl;
    cout << "hex (base = 16): " << setbase(16) << n << endl;
    cout << "After using setbase: " << n << endl;
    cout << endl;

    // setprecision && fixed
    double PI = 3.14159265359;

    cout << PI << endl;
    cout << setprecision(4) << PI << endl;
    cout << fixed << setprecision(4) << PI << endl;
    cout << "After using setprecision && fixed: " << PI << endl;
    cout << endl;

    // setw && setfill
    // use setbase(10) and fixed << setprecision(5) to reset cout
    cout << setbase(10) << n << endl;
    cout << setw(8) << n << endl;
    cout << setw(8) << setfill('0') << n << endl;
    cout << setw(8) << fixed << setprecision(5) << PI << endl;
    cout << setw(8) << fixed << setprecision(4) << PI << endl;

    return 0;
}