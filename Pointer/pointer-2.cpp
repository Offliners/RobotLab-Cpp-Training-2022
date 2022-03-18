#include<iostream>

using namespace std;

int main(void)
{
    int arr1[5]={}, arr2[3][4]={},
    *ptr=0;

    ptr = &arr1[2];
    *ptr = 20;
    *(ptr+1) = 30;
    ptr[2] = 40;

    ptr = &arr2[1][3];
    *ptr = 50;
    ptr[1] = 60;

    cout << "arr1 : ";
    for(int i = 0; i < 5; ++i)
        cout << arr1[i] << " ";
    
    cout << endl;

    cout << "arr2 : ";
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
            cout << arr2[i][j] << " ";
        
        cout << "| ";
    }
    
    cout << endl;

    return 0;
}
