#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int inf=1e9;
    vector<int> dp(n,inf);
    vector<int> minAns(n+1,inf);
    dp[0]=0;
    minAns[A[0]]=0;
    for(int i=1;i<n;i++)
    {
        if(A[i-1] <= A[i])
        {
            dp[i]=dp[i-1]; // continue in prev
        }
        dp[i]=min(dp[i],1 + minAns[A[i]]);
        minAns[A[i]]=min(minAns[A[i]],dp[i]);
    }
    if(dp[n-1]!=inf)
    cout<<dp[n-1]<<endl;
    else cout<<-1<<endl;
}
int main()
{
    

    int t; cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}