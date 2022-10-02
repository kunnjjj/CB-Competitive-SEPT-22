#include<bits/stdc++.h>
using namespace std;


int power(int a,int b, int M=(int)1e9+7)
{
    int res=1;
    int p=a%M;

    while(b>0)
    {
        if(b&1)
        {
            res=(1LL * res * p)%M;
        }
        p=(1LL * p*p)%M;
        b>>=1;
    }
    // cout<<"res: "<<res<<endl;
    return res;
}

int main()
{

    int t; cin>>t;
    while (t--)
    {
        int a,b; cin>>a>>b;
        cout<<power(a,b)<<endl;
    }
    



    return 0;
}