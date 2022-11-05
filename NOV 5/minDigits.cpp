#include<bits/stdc++.h>
using namespace std;


int main()
{

    int max_n=1e6;

    int inf=1e9;
    vector<int> dp(max_n+1,inf);


    // dp[i] min steps to reach 0 from i

    dp[0]=0;
    for(int i=1;i<=max_n;i++)
    {
        int x=i;
        while(x>0)
        {
            int dig=x%10;
            dp[i]=min(dp[i], 1+ dp[i-dig]);
            x/=10;
        }
    }
    
    int n; cin>>n;
    cout<<dp[n]<<endl;



    return 0;
}