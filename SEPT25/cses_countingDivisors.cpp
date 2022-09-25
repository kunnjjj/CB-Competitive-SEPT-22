// https://cses.fi/problemset/task/1081
#include<bits/stdc++.h>
using namespace std;
int max_n=1e6;
vector<int> sieve(max_n+1,1);
vector<int> max_prime(max_n+1,1);
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
void make_max_prime()
{
    for(int i=2;i<=max_n;i++)
    {
        if(sieve[i])
        {
            for(int j=i;j<=max_n;j+=i)
            {
                max_prime[j]=i;
            }
        }
    }
}

void solve()
{
    int x; cin>>x;
    long long ans=1;
    while(x>1)
    {
        int cur_prime=max_prime[x];
        int cnt=1; // we have (cnt+1) options (cur^0 ,cur^1 ... cur^cnt)
        while (x>1 && max_prime[x]==cur_prime)
        {
            cnt++;
            x/=cur_prime;
            /* code */
        }
        ans*=(cnt);
    }
    cout<<ans<<endl;

}
int main()
{
    sieve2();
    make_max_prime();
    int t; cin>>t;
    
    while (t--)
    {
        solve();
        /* code */
    }
    




    return 0;
}