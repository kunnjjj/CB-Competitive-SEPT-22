#include<bits/stdc++.h>
using namespace std;

int max_n=1e6;
int best_ans=0;

vector<int> dp(max_n+1,-1);
int lis(int i,vector<int> &A) 
{
// lis[i]=longest inc. subs. upto idx=i,
// including index=i
    if(i==-1) return 0;

    if(dp[i]!=-1) return dp[i];
    int myAns=1;

    for(int j=i-1;j>=0;j--)
    {
        if(A[j] < A[i]) // i can a seq of len 1+dp[j]
        {
            myAns=max(myAns,lis(j,A));
        }
    }

    best_ans=max(best_ans,myAns);

    return dp[i]=myAns;
}

int main()
{
    
    int n; cin>>n;
    vector<int> A(n);
    for(int &x:A) cin>>x;   

    // lis(n-1,A);
    // ans is athough max(lis(i,A)) where i=0..n-1,
    //  but we can maintain max variable

    // cout<<best_ans<<endl;

    vector<int> dp;
    vector<int> jump(n);
    
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
    }
    cout<<(int)dp.size()<<endl;
    // while(idx>=0)
    // {
    //     ans.push_back(A[idx]);
    //     idx=A[idx];
    // }
    // reverse(ans.begin(),ans.end());
    // for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}
