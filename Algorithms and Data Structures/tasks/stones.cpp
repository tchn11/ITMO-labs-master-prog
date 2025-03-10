#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool dp[11][11] = {false};

    for (int i = 0; i <= 10; ++i) 
    {
        for (int j = 0; j <= 10; ++j) 
        {
            if (i == 0 && j == 0) 
                continue;
            
            bool can_win = false;

            if (i > 0 && !dp[i-1][j]) 
                can_win = true;
            if (j > 0 && !dp[i][j-1]) 
                can_win = true;
            if (i > 0 && j > 0 && !dp[i-1][j-1]) 
                can_win = true;
            
            dp[i][j] = can_win;
        }
    }

    cout << (dp[n][m] ? "Win" : "Lose") << endl;
    return 0;
}