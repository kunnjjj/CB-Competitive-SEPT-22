#include <bits/stdc++.h>
using namespace std;

vector<int> dp((int)1e6 + 1, 0);
int M = 1e9 + 7;

int f(int n)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int dice = 1; dice <= 6; dice++)
    {
        if (n - dice >= 0)
            ans += f(n - dice);
        ans %= M;
    }
    return dp[n] = ans;
}
// LLONG_MAX
int main()
{
    int n;
    cin >> n;
    // cout<<f(n)<<endl;
    dp[0]=1;
    vector<int> prefix((int)1e6+1);
    prefix[0]=1;

    for(int i=1;i<=n;i++)
    {   
        // dp[i] num of ways to get sum=i
        // for(int dice=1;dice<=6;dice++)
        // {
            
        //     dp[i]+=(i-dice>=0?dp[i-dice]:0);
        //     dp[i]%=M;
        // }
        // dp[i]=dp[i-1] + dp[i-2] + ... + dp[i-k]
        int k=6;
        dp[i]=((prefix[i-1] - (i-k-1>=0?prefix[i-k-1]:0))%M + M)%M;
        prefix[i]=(prefix[i-1] + dp[i])%M;
    }
    
    cout<<dp[n]<<endl;

    return 0;
}



