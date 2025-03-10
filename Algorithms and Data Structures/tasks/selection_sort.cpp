#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int numbers[n];

    for (int i=0; i < n; i++)
        cin >> numbers[i];

    for (int i = 0; i < n-1; i++)
    {
        int local_min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (numbers[j] < numbers[local_min])
            {
                local_min = j;
            }
        }
        if (local_min != i)
        {
            swap(numbers[i], numbers[local_min]);
        }
    }

   for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";

    return 0;
}
