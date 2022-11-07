#include<bits/stdc++.h>
using namespace std;


void func(vector<int> &A)
{
    int n=A.size();
    vector<int> prefix(n);
    vector<int> sumOfProdOfPairs(n);


    int ans=0;

    // for(int i=n-1;i>=0;i--)
    // {
        // prefix[i]=(i+1<n?prefix[i+1]:0) + A[i];
        // sumOfProdOfPairs[i]=A[i] * (i+1<n?prefix[i+1]:0);
        // sumOfProdOfPairs[i]+=(i+1<n?sumOfProdOfPairs[i+1]:0);
        // ans+=(A[i] * (i+1<n?sumOfProdOfPairs[i+1]:0));
    // }

    int oldProdOfPairs=0,oldPrefSum=0;
    for(int i=n-1;i>=0;i--)
    {
        
        int newPrefixSum=oldPrefSum + A[i];
        int newSumOfProdOfPairs= A[i] * oldPrefSum;
        newSumOfProdOfPairs += oldProdOfPairs;
        ans+=A[i] * oldProdOfPairs;

        oldPrefSum=newPrefixSum;
        oldProdOfPairs=newSumOfProdOfPairs;
    }

    
    cout<<ans<<endl;

// [3,4,5,66,1,32]
// [-,-,ans]
// 5 * (66 + 1 + 32)  + 66 * (1 + 32) + 1 * 32

}
int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int &x:A) cin>>x;
    func(A);

    return 0;
}