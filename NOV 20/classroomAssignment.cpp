#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int max_n = 25;
    vector<vector<int>> nCr(max_n + 1, vector<int>(max_n + 1));

    for (int i = 0; i <= max_n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                nCr[i][j] = 1;
                continue;
            }

            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
        }
    }
    // cout<<nCr[25][12]<<endl;
    // cout<<nCr[5][0]<<endl;

    // ans+=nCr[i][j];
    // for(int i=1;i<=t;i++)
    // {
    //     int n; cin>>n;
    //     int ans=0;
    //     for(int a_=0;a_<=n;a_++)
    //     {
    //         int b_=n-a_;
    //         if(a_+1>=b_)
    //         ans+=nCr[a_+1][b_];
    //     }
    // 	cout<<"#"<<i<<" : ";
    //     cout<<ans<<endl;
    // }
    int n = 25;

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        // dp[i][0] i len ki string, last mein 'a' aarha ho
        // dp[i][1] i len ki string, last mein 'b' aarha ho
        int ans = dp[n][0] + dp[n][1];
        cout << "#" << i << " : ";
        cout << ans << endl;
    }

    // dp[i][0] i len ki string, last mein 'a' aarha ho
    // dp[i][1] i len ki string, last mein 'b' aarha ho

    return 0;
}