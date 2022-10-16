#include<bits/stdc++.h>
using namespace std;


void printSet(set<pair<int,int>> &s)
{
    for(pair<int,int> p:s)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
}
void solve()
{
    int n,k; cin>>n>>k;


    if(k==0)
    {
        // printSet(s);
        for(int i=0;i<n/2;i++)
        {
            cout<<i<<" "<<n-1-i<<endl;
        }
        return ;
    }

    if(n==4 && k==3)
    {
        cout<<-1<<endl;
        return ;
    }

    if(k!=n-1)
    {
        int ans=0;
        cout<<0<<" "<<n-1-k<<endl;
        ans+=(0&(n-1-k));
        cout<<k<<" "<<n-1<<endl;
        ans+=(k&(n-1));
        for(int i=1;i<n/2;i++)
        {
            int j=n-1-i;

            if(i!=k && j!=n-1-k && i!=n-1-k)
            {
                ans+=(i&j);
                cout<<i<<" "<<j<<endl;
            }

        }
        assert(ans==k);
        // printSet(s);
        return ;    
    }
    int ans=0;
    cout<<n-1<<" "<<n-2<<endl;
    ans+=((n-2)&(n-1));
    cout<<0<<" "<<2<<endl;
    ans+=(0&2);
    cout<<1<<" "<<n-3<<endl;
    ans+=(1&(n-3));
    // cout<<3<<" "<<n-4<<endl;
    for(int i=3;i<n/2;i++)
    {
        cout<<i<<" "<<n-1-i<<endl;
        ans+=(i&(n-i-1));
    }
    assert(ans==k);
    // cout<<ans<<endl;

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