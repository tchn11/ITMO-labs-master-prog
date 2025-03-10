#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long S;
    cin >> n >> S;
    
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) 
        cin >> prices[i];
    
    sort(prices.begin(), prices.end());
    
    long long total = 0;
    int count = 0;
    
    for (int price : prices) 
    {
        if (total + price <= S) 
        {
            total += price;
            count++;
        } 
        else 
            break;
    }
    
    cout << count << endl;
    
    return 0;
}