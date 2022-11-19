#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
 
    int n,W; cin>>n>>W;
    vector<int> wt(n),val(n);
 
 
    int total=0;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
        total+=val[i];
    }
    long long inf=1e10;
 
    vector<vector<long long>> dp(n+1,vector<long long> (total+1,inf));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int v=0;v<=total;v++)
        {
            // dp[i][v]=min weight to get value=v,
            // and we are choosing from 0....i
 
            // dp[i][v]
            long long choose = inf,not_choose=inf;
 
            if(val[i]<=v) // TODO
            {
                choose=wt[i] + (i-1>=0?dp[i-1][v-val[i]]:0);
                if(i-1>=0)
                {
                    choose=wt[i] + dp[i-1][v-val[i]];
                }
                else
                {
                    if(v==val[i])
                    {
                        choose=wt[i];
                    }
                    else
                    {
                        choose=inf;
                    }
                }
            }
            
            not_choose=((i-1>=0?dp[i-1][v]:(v==0?0:inf)));
            
 
            dp[i][v]=min(choose,not_choose);
            if(dp[i][v]<=W)
            {
                ans=max(ans,v);
            }
            // cout<<"i: "<<i<<endl;
            // cout<<"v: "<<v<<endl;
            // cout<<"dp: "<<dp[i][v]<<endl;
            // cout<<endl;
        }
    }
    // cout<<dp[n-1][90]<<endl;
    // cout<<dp[0][140]<<endl;
    // by choosing 0...0
    // to get val = 140 i will need weight of 3
    cout<<ans<<endl;
 
    return 0;
}