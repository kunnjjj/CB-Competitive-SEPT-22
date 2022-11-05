#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,k; cin>>n>>k;
    vector<int> A(n);
    for(int &x:A) cin>>x;
    int inf=1e9;

    vector<int> dp((int)1e6+1,inf);

    dp[0]=0;

    for(int i=1;i<=k;i++)
    {
        // dp[i] min coins to get sum=i
        for(int coin:A)
        {
            if(i-coin>=0)
            dp[i]=min(dp[i],1 + dp[i-coin]);
        }
    }
    
    if(dp[k]==inf)
    {
        cout<<-1<<endl;
    }
    else
    cout<<dp[k]<<endl;


    return 0;
}