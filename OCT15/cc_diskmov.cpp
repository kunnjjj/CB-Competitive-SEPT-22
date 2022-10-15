#include<bits/stdc++.h>
using namespace std;

long long func(set<int> not_taken,set<int> A,int k)
{
    long long ans=0;
    while (k--)
    {
        int chota=*not_taken.begin();
        not_taken.erase(chota);
        A.insert(chota);
        ans+=(*A.rbegin()-chota);
    }
    return ans;
    
}
void solve()
{
    int n; cin>>n;
    int k; cin>>k;

    set<int> not_taken;
    for(int i=1;i<=2*n;i++) not_taken.insert(i);
    set<int> A;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        A.insert(x);
        not_taken.erase(x);
    }

    long long op1=func(not_taken,A,k);
    long long op2=0;
    auto it=not_taken.find(2*n); // originally nahi hai

    if(it!=not_taken.end())
    {
        // ms.erase(5);  saari entries gayab
        // auto it=ms.find(val); if(it!=ms.end()){ms.erase(it)}
        k--;
        not_taken.erase(it);
        A.insert(2*n);
        op2=func(not_taken,A,k);
    }
    cout<<max(op1,op2)<<endl;

}
int main()
{

    int t; cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    

    return 0;
}