#include<bits/stdc++.h>
using namespace std;



template<typename T>
void _print(T x)
{
    cout<<x<<" ";
}

void _print(string x)
{
    cout<<"\"";
    cout<<x;
    cout<<"\"";
}


template<typename T>
void _print(vector<T> x)
{
    cout<<"{";
    for(int i=0;i<(int)x.size();i++)
    {
        _print(x[i]);
        cout<<", ";
    }
    cout<<"}"<<endl;
}

#define deb(x) cout<<#x<<" : ";_print(x);cout<<endl;
#define all(x) x.begin(),x.end()


vector<int> get_mx_len(vector<int> &A)
{
    int n=A.size();
    vector<int> ans(n);
    vector<int> dp;
    // vector<int> jump(n);
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(dp.begin(),dp.end(),A[i]);
        int idx=it-dp.begin();
        if(idx!=(int)dp.size())
        {
            // (*it)=A[i];
            dp[idx]=A[i];
            
        }
        else
        {
            dp.push_back(A[i]);
          

        }
        ans[i]=(int)dp.size();
    }
    // cout<<(int)dp.size()<<endl;
    return ans;
}

void solve()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int& x:A) cin>>x;
    // deb(A);
    vector<int> left=get_mx_len(A);
    // deb(left);
    reverse(all(A));
    for(int i=0;i<n;i++) A[i]*=-1;
    vector<int> right=get_mx_len(A);
    reverse(all(right));
    // deb(right);
    int ans=1;
    for(int i=0;i+1<n;i++)
    {
        ans=max(ans,left[i] + right[i+1]);
    }
    cout<<ans<<endl;

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