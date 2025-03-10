#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int** arrays = (int**) malloc(sizeof(int*) * n);
    int* sizes = (int*) malloc(sizeof(int) * n);

    int summ = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> sizes[i];
        summ += sizes[i];
        arrays[i] = (int*) malloc(sizeof(int) * sizes[i]);
        for (int j = 0; j < sizes[i]; j++)
            cin >> arrays[i][j];
    }

    int* ptrs = (int*) malloc(sizeof(int) * n);
    memset(ptrs, 0, n);

    for (int i = 0; i < summ; i++)
    {
        int min = INT_MAX;
        int min_num = 0;
        for (int j = 0; j < n; j++)
        {
            if (ptrs[j] == sizes[j])
                continue;

            if (min > arrays[j][ptrs[j]])
            {
                min = arrays[j][ptrs[j]];
                min_num = j;
            }
        }

        cout << min << " ";

        ptrs[min_num] ++;
    }
}