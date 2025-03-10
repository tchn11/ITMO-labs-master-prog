#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void quick_sort(vector<signed long long>& arr, int l, int r)
{
    int left = l;
    int right = r;
    int mid = arr[(left + right) / 2];

    while (left <= right) 
    {
        while (arr[left] < mid) 
            left++;
        while (arr[right] > mid)
            right--;
        if (left <= right)
            swap(arr[left++], arr[right--]);
    }
    if (l < right) 
        quick_sort(arr, l, right);
    if (r > left) 
        quick_sort(arr, left, r);
}

int main()
{
    int n;
    cin >> n;
    vector<signed long long> numbers(n);

    for (int i=0; i < n; i++)
        cin >> numbers[i];

   quick_sort(numbers, 0, n-1);

    signed long long max_answer = LONG_LONG_MIN;
    signed long long four_last = numbers[n-4] * numbers[n-3] * numbers[n-2] * numbers[n-1];
    signed long long four_first = numbers[0] * numbers[1] * numbers[2] * numbers[3];
    signed long long two_first_two_last = numbers[0] * numbers[1] * numbers[n-2] * numbers[n-1];

   if(four_first > max_answer)
    max_answer = four_first;
   if(four_last > max_answer)
    max_answer = four_last;
   if(two_first_two_last > max_answer)
    max_answer = two_first_two_last;

    cout << max_answer;
    return 0;
}
