#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long numbers[n];

    for (int i=0; i < n; i++)
        cin >> numbers[i];

    unsigned long max1 =  0;
    int max1_index = 0;
    unsigned long max2 = 0;
    for (int i = 0; i < n; i++) 
    { 
        if (max1 < numbers[i]) 
        {
            max1 = numbers[i];
            max1_index = i; 
        }
    }

    numbers[max1_index] = 0;

    for (int i = 0; i < n; i++) 
    { 
        if (max2 < numbers[i]) 
        {
            max2 = numbers[i];
        }
    }

    cout << max1 * max2;
    return 0;
}