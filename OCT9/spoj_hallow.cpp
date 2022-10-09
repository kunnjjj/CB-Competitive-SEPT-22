#include<bits/stdc++.h>
using namespace std;
// https://www.spoj.com/status/ns=30173769

void solve(int c,int n)
{

    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    vector<long long> prefix(n);

    for(int i=0;i<n;i++)
    {
        prefix[i]=(i-1>=0?prefix[i-1]:0) + A[i];
    }

    // cout<<"prefix: "<<endl;
    for(int i=0;i<n;i++)
    {
        prefix[i]%=c;
        // cout<<prefix[i]<<" ";
    }
    // cout<<endl;

    map<int,int> mp; //{mod,idx}

    mp[0]=-1;

    for(int i=0;i<n;i++)
    {
        auto it=mp.find(prefix[i]);
        if(it!=mp.end())
        {
            int vohIndex=(*it).second;
            for(int j=vohIndex+1;j<=i;j++)
            {
                cout<<j+1<<" ";
            }
            cout<<endl;
            return ;
        }
        mp[prefix[i]]=i;
    }


    // zaroorat nahi padegi for no sweets case




}
int main()
{

    while (1)
    {

        int c,n; cin>>c>>n;
        if(c==0 && n==0)
        {
            return 0;
        }
        solve(c,n);
        /* code */
    }
    


    return 0;
}