#include<bits/stdc++.h>
using namespace std;
int power(int a,int b)
{
    if(b==0) return 1;

    int halfAns=power(a,b/2);
    if(b&1)
    {
        return a * halfAns * halfAns;
    }
    return halfAns * halfAns;
}

int powerIterative(int a,int b)
{
    int p=a;
    int res=1;
    while (b>0)
    {
        if(b&1)
        {
            res*=p;
        }
        p*=p;
        b>>=1;
    }
    return res;
}
int main()
{
    int n,m; cin>>n>>m;

    cout<<power(n,m)<<endl;
    cout<<powerIterative(n,m)<<endl;





    return 0;
}