#include <iostream>
#include <stdint.h>
#include <cstdlib>
using namespace std;

void merge_sort(int *arr, int left, int right)
{
    if (left == right)
        return;
    
    int mid = (left + right)/2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;

    int* temp_arr = (int*)malloc((right + 1) * sizeof(int));

    for (int k = 0; k < right - left + 1; k++)
    {
        if ((j > right) || ((i <= mid) && (arr[i] < arr[j])))
        {
            temp_arr[k] = arr[i];
            i++;
        }
        else
        {
            temp_arr[k] = arr[j];
            j++;
        }
    }

    for (int k = 0; k < right - left + 1; k++)
        arr[left + k] = temp_arr[k];
    
    free(temp_arr);
}

int main()
{
    int n;
    cin >> n;
    int numbers[n];

    for (int i=0; i < n; i++)
        cin >> numbers[i];
    
    merge_sort(numbers, 0, n - 1);

   for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";

    return 0;
}
