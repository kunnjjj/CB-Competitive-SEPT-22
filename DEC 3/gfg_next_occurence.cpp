// https://practice.geeksforgeeks.org/contest/coders-combat-battlefield-dtu/problems/#
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    long long mexSum(int N, string S) {
        
        int last_zero=N,last_one=N;
        long long ans=0;
        for(int i=N-1;i>=0;i--)
        {
            if(S[i]=='0')
            {
                last_zero=i;
                ans+=(last_one-i);
                ans+=2LL * (N-last_one);
            }
            else
            {
                last_one=i;
                ans+=2LL * (N-last_zero);
            }
        }
        return ans;
        // code here
    
        // vector<int> zeros;
        // vector<int> ones;
        // for(int i=0;i<N;i++)
        // {
        //     if(S[i]=='0') zeros.push_back(i);
        //     else ones.push_back(i);
        // }
        // long long ans=0;
        // for(int i=0;i<N;i++)
        // {
        //     if(S[i]=='0')
        //     {
        //         auto it=lower_bound(ones.begin(),ones.end(),i); 
        //         // we can also use
        //         // lower_bound(i+1)
        //         // upper_bound(i)
                
                
        //         int occ_1;
        //         if(it==ones.end())
        //         {
        //             occ_1=N;
        //         }
        //         else
        //         {
        //             occ_1=*it;
        //         }
                
        //         ans+=(occ_1-i);
        //         ans+=2LL * (N-occ_1);
        //     }
        //     else
        //     {
        //         // int occ_0=next_occ[i][0];
        //         auto it=lower_bound(zeros.begin(),zeros.end(),i);
        //         int occ_0;
        //         if(it==zeros.end())
        //         {
        //             occ_0=N;
        //         }
        //         else
        //         {
        //             occ_0=*it;
        //         }
        //         ans+=(N-occ_0) * 2LL;
        //     }
        // }
        // return ans;
        
        // vector<vector<int>> next_occ(N+1,vector<int> (2,N));
        // long long ans=0;
        // for(int i=N-1;i>=0;i--)
        // {
        //     next_occ[i]=next_occ[i+1];
        //     next_occ[i][S[i]-'0']=i;
        // }
        
        
        // for(int i=0;i<N;i++)
        // {
        //     if(S[i]=='0')
        //     {
        //         int occ_1=next_occ[i][1];
        //         ans+=(occ_1-i);
        //         ans+=2LL * (N-occ_1);
        //     }
        //     else
        //     {
        //         int occ_0=next_occ[i][0];
        //         ans+=(N-occ_0) * 2LL;
        //     }
        // }
        // return ans;
    }

};


// { Driver Code Starts.
int main() {

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin>>N;
        string S;
        cin>>S;
        Solution ob;
        long long y = ob.mexSum(N, S);

        cout<<y<<endl;
    }

    return 0;
}  // } Driver Code Ends