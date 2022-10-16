#include<bits/stdc++.h>
using namespace std;
int power(int a,int b,int M=(int)1e9+7)
{
    if(b==0) return 1;

    int half=power(a,b/2);
    half=(1LL * half * half)%M;
    if(b&1)
    {
        return (1LL * a * half)%M;
    }
    return half;
}


int main()
{
    int M=1e9+7;
    int max_n=1e6;
    vector<int> fact(max_n+1);
    fact[0]=1;
    for(int i=1;i<=max_n;i++)
    {
        fact[i]=(1LL * fact[i-1] * i)%M;
    }

    vector<int> inv_fact(max_n+1);

    for(int i=0;i<=max_n;i++)
    {
        inv_fact[i]=power(fact[i],M-2,M);
    }

    int t; cin>>t;
    while(t--)
    {
        int n,r; cin>>n>>r;
        int nr=fact[n]; //n!
        int dr=(1LL * inv_fact[r] * inv_fact[n-r])%M; // (r! * (n-r)!)
        int ans=(1LL * nr * dr)%M;
        cout<<ans<<endl;
    }



    return 0;
}