#include<iostream>
#include<vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    int M=1e9+7;
    int n=(1e6);
    
        vector<vector<int>> dp(n+1,vector<int> (2));

        dp[1][0]=1;
        dp[1][1]=1;

        for(int i=2;i<=n;i++)
        {
            dp[i][0]= (0LL + dp[i-1][1] + (dp[i-1][0] *2LL)%M )%M;
            dp[i][1]=(0LL + dp[i-1][0] + (4LL* dp[i-1][1])%M)%M;
        }
    while(t--)
    {
        int n; cin>>n;
        cout<<(dp[n][0] + dp[n][1])%M<<"\n";


    }

    return 0;
}