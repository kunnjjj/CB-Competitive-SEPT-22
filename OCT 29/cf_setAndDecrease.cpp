#include <bits/stdc++.h>
using namespace std;
#define int long long

long long ceil_div(long long a,long long b)
{
    return (a+b-1)/b;
}
void solve()
{

    int n;
    cin >> n;
    vector<int> A(n);
    long long k; cin>>k;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    vector<long long> prefix(n);
    for(int i=0;i<n;i++)
    {
        prefix[i]=(i-1>=0?prefix[i-1]:0) + A[i];
    }

    long long inf=1e18;
    long long ans=inf;
    if(prefix[n-1] <=k)
    {
        cout<<0<<endl;
        return ;
    }

    for(int assigments=0;assigments<=n-1;assigments++)
    {
        long long P=(prefix[n-assigments-1] - prefix[0]) ;
        long long RHS= (P+ (assigments + 1)*1LL * A[0] -k);
        long long R=ceil_div(RHS,assigments+1);
        R=max(R,0LL);
        long long op=(R + assigments);
        // op=max(op,0LL);
        ans=min(ans,op);
    }
    cout<<ans<<endl;

}
signed main()
{
    int t; cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    

    return 0;
}