#include<bits/stdc++.h>
using namespace std;


int main()
{

    int n,W; cin>>n>>W;
    vector<int> wt(n),val(n);

    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }

    vector<vector<long long>> dp(n+1,vector<long long> (W+1));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int w=0;w<=W;w++)
        {
            // dp[i][w]: max value we can get from choosing among i....N-1
            // with w value left
            long long choose=0,not_choose=0;
            if(wt[i]<=w)
            {
                choose=val[i] + dp[i+1][w-wt[i]];
            }
            not_choose=dp[i+1][w];
            dp[i][w]=max(choose,not_choose);
        }
    }

    cout<<dp[0][W]<<endl;
    return 0;
}