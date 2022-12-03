#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int dig = 0; dig <= k; dig++)
        {
            if (i == 1)
            {
                dp[i][dig] = 1;
                continue;
            }

            if (dig == 0)
            {
                dp[i][dig] += dp[i - 1][0];  //+1
                for (int x = 2; x <= k; x++) //+7
                {
                    dp[i][dig] += dp[i - 1][x]; //
                }
                if (i == 2)
                {
                    if(k>=1)
                    dp[i][dig]+=1;
                    else 
                    dp[i][dig]+=0;

                }
                else
                {
                    for (int x = 1; x <= k; x++)
                    {
                        dp[i][dig] += dp[i - 2][x];
                    }
                }
            }
            else
            {
                for (int x = 0; x <= k; x++)
                {
                    dp[i][dig] += dp[i - 1][x];
                }
            }
        }
        cout << "i: " << i << endl;
        for (int x = 0; x <= k; x++)
            cout << "x: " << x << ", dp: " << dp[i][x] << endl;
        cout << endl;
    }
    int ans = 0;
    for (int dig = 0; dig <= k; dig++)
    {
        ans += dp[n][dig];
    }
    cout << ans << endl;

    return 0;
}