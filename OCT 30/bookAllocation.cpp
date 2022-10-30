#include <bits/stdc++.h>
using namespace std;


bool is_poss_to_assign_mid(vector<int> &A,long long mid,int s)
{
    int i=0;
    int n=A.size();
    while(i<n && s>0)
    {
        long long cur=0;   
        while(i<n && cur + A[i]<=mid)
        {
            cur+=A[i];
            i++;
        }
        s--;
    }

    return s>=0 && i==n;

    
}
void solve()
{
    int n, st;
    cin >> n >> st;
    vector<int> A(n);
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
        mx = max(mx, (long long)A[i]);
    }
    long long s=mx,e=sum;
    long long ans=1e18;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        if(is_poss_to_assign_mid(A,mid,st))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<ans<<endl;
}

int main()
{

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

// long long ans=1e9;
// for(int x:factors)
// {
//     // har segment ka sum=x
//     int get=func(A,x);
//     ans=min(ans,get);
// }
// cout<<ans<<endl;

// for(int i=1;i*i<=sum;i++)
// {
//     if(sum%i==0)
//     {
//         // factors.push_back(i);
//         ans=min(ans,get(A,i));

//         if((sum/i)!=i)
//         {
//             // factors.push_back(sum/i);
//             ans=min(ans,get(A,i));
//         }
//     }
// }
