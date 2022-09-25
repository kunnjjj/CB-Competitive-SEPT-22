// https://hack.codingblocks.com/app/contests/1236/1039/problem
#include<bits/stdc++.h>
using namespace std;
int max_n=1e6;
vector<int> sieve(max_n+1,1);
void sieve2()
{
    

    sieve[0]=0;
    sieve[1]=0;

    // max_n=25

    for(int i=2;i*i<=max_n;i++)
    {
        // i=2......
        // i=3....
        // i=4 -
        // i=5 ......
        // i=6 ...
        if(sieve[i])
        {
            for(int j=i*i;j<=max_n;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
}


int main()
{
    int t; cin>>t;
    sieve2();

    vector<int> prefix(max_n+1);
    for(int i=2;i<=max_n;i++)
    {
        prefix[i]=prefix[i-1] + sieve[i];
    }
    
    while (t--)
    {
        int n,m; cin>>n>>m;
        int cnt=0;
        // for(int i=n;i<=m;i++)
        // {
        //     cnt+=sieve[i];
        // }
        cnt=prefix[m]-prefix[n-1];

        cout<<cnt<<endl;
    }
    




    return 0;
}