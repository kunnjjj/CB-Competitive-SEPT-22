//  https://www.codechef.com/problems/TSOH

#include<bits/stdc++.h>
using namespace std;

void _print(int x)
{
    cout<<x<<endl;
}

void _print(vector<long long> &A)
{
    for(int x:A) cout<<x<<" ";
    cout<<endl;
}


#define deb(x) cout<<#x<<": ";_print(x);

int main()
{
    int n; cin>>n;

    // deb(n);

    vector<long long> A(n);

    for(int i=0;i<n;i++) cin>>A[i];

    vector<long long> best_left(n); // best_left[i] stores best sum ending in i
    vector<long long> best_right(n);
    for(int i=0;i<n;i++)
    {
        best_left[i]=max((i-1>=0?best_left[i-1]:0) + A[i], // continue
                            (long long)A[i]); // naya subarray
    }


    for(int i=n-1;i>=0;i--)
    {
        best_right[i]=max((i+1<n?best_right[i+1]:0) + A[i],
                            (long long)A[i]);
    }

    
    

    vector<long long> mx_left(n), //mx_left[i] stores ans for kadane in [0....i]
    mx_right(n); // mx_right[i] stores ans for kadane in [i....n-1]

    long long inf=(int)1e10;
    for(int i=0;i<n;i++)
    {
        mx_left[i]=max((i-1>=0?mx_left[i-1]:-inf),(long long)best_left[i]);
    }


    for(int i=n-1;i>=0;i--)
    {
        mx_right[i]=max((i+1<n?mx_right[i+1]:-inf),(long long)best_right[i]);
    }

    long long ans=-inf;
    for(int i=0;i+1<n;i++)
    {
        ans=max(ans,mx_left[i] + mx_right[i+1]);
    }

    // deb(best_left);
    // deb(mx_left);
    // cout<<endl;
    // deb(best_right);
    // deb(mx_right);
    

    cout<<ans<<endl;

    return 0;
}