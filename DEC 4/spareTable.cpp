#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    int max_n = 1e5;
    vector<int> LOG(max_n + 1);
    LOG[1] = 0;
    for (int i = 2; i <= max_n; i++)
    {
        LOG[i] = 1 + LOG[i / 2];
    }

    int j_max = LOG[n];

    // int dp[n][j_max + 1] = {0};
    vector<vector<int>> dp(n,vector<int> (j_max+1));
    for (int j = 0; j <= j_max; j++)
    {
        int len = (1 << j);
        for (int i = 0; i + len - 1 < n; i++)
        {
            if (j == 0)
            {
                dp[i][j] = A[i];
                continue;
            }
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int qL, qR;
        cin >> qL >> qR;
        int x = LOG[qR - qL + 1];
        // cout<<"qL: "<<qL<<endl;
        cout << min(dp[qL][x], dp[qR + 1 - (1 << x)][x]) << endl;
    }

    return 0;
}
