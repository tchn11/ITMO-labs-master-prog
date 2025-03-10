#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool dp[1001][1001] = {false};

    for (int i = 0; i <= 1000; ++i) 
    {
        for (int j = 0; j <= 1000; ++j) 
        {
            if (i == 0 && j == 0) 
                continue;

            bool canWin = false;

            if (i > 0 && !dp[i-1][j]) 
                canWin = true;
            if (j > 0 && !dp[i][j-1]) 
                canWin = true;
            if (i - 2 >= 0 && !dp[i-2][j]) 
                canWin = true;
            if (j - 2 >= 0 && !dp[i][j-2]) 
                canWin = true;
            if (i > 0 && j - 2 >= 0 && !dp[i-1][j-2]) 
                canWin = true;
            if (j > 0 && i - 2 >= 0 && !dp[i-2][j-1]) 
                canWin = true;

            dp[i][j] = canWin;
        }
    }

    cout << (dp[n][m] ? "Win" : "Lose") << endl;
    return 0;
}
