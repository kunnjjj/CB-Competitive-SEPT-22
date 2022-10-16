#include<bits/stdc++.h>

using namespace std;
void solve()
{   
    int n; cin>>n;

    vector<int> A(n+1);
    long long ans=0;
    int dp=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        int dpNow=min(dp+1,x);
        ans+=dpNow;
        dp=dpNow;
    }
    cout<<ans<<endl;
    // for(int i=1;i<=n;i++) cin>>A[i];

    // stack<pair<int,int>> s;
    // s.push({n+1,INT_MIN});

    // for(int i=n;i>=1;i--)
    // {
    //     s.push({i,A[i]-i});
    // }
    // int inc=0;
    // long long ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     while(s.top().first!=n+1 && s.top().second+inc>=0)
    //     {
    //         s.pop();
    //     }

    //     int rukawat=s.top().first;
    //     ans+=(rukawat-i);
    //     inc++;
    // }
    // cout<<ans<<endl;


}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}