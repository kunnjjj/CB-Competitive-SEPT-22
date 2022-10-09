#include <bits/stdc++.h>
using namespace std;

int max_n = 1e7;

vector<int> sieve(max_n + 1, 1);
vector<int> max_prime(max_n + 1, 1);

void make_sieve()
{
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i <= max_n; i++)
    {
        if (sieve[i])
        {
            for (int j = 2*i; j <= max_n; j += i)
                sieve[j] = 0;
        }
    }
}

void make_max_prime()
{
    for (int i = 2; i <= max_n; i++)
    {
        if (sieve[i])
            for (int j = i; j <= max_n; j += i)
                max_prime[j] = i;
    }
}



int mod_mul(long long a, long long b, int M = (int)1e9 + 7)
{
    a %= M;
    b %= M;
    return ((1LL * a * b) % M + M) % M;
}

int mod_add(long long a, long long b, int M = (int)1e9 + 7)
{
    a %= M;
    b %= M;
    return ((a + b) % M + M) % M;
}

int mod_sub(long long a, long long b, int M = (int)1e9 + 7)
{
    a %= M;
    b %= M;
    return ((a - b) % M + M) % M;
}

int power(long long a, long long b, int M = (int)1e9 + 7)
{

    a %= M;
    long long res = 1;
    long long p = a;
    while (b > 0)
    {
        if (b&1)
        {
            res = mod_mul(res, p,M);
        }
        p = mod_mul(p, p,M);
        b >>= 1;
    }
    return res;
}


// int power(int a,int b, int M=(int)1e9+7)
// {
//     int res=1;
//     int p=a%M;

//     while(b>0)
//     {
//         if(b&1)
//         {
//             res=(1LL * res * p)%M;
//         }
//         p=(1LL * p*p)%M;
//         b>>=1;
//     }
//     // cout<<"res: "<<res<<endl;
//     return res;
// }

int mod_inverse(long long a, int M = (int)1e9 + 7)
{

    int phiM = M - 1;
    a %= M;
    int inv = power(a, phiM - 1, M);

    return inv;
}


void solve()
{
    int n,k; cin>>n>>k;    
    long long res=n;

    map<int,int> mp;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while (n%i==0)
            {
                mp[i]++;
                n/=i;
                /* code */
            }
            
        }
    }

    if(n>1)
    {
        mp[n]++;
    }
    // cout<<"n: "<<n<<endl;
    // cout<<"k: "<<k<<endl;
    // long long res=n;

    int M=1e9+7;
    int phiM=M-1;
    for(pair<int,int> p:mp)
    {

        int cur_prime=p.first;
        int pr=cur_prime;
        int cnt=p.second;

        int ar=cnt;

        int t1=power(2,k,phiM);
        
        // cout<<"t1: "<<t1<<endl;
        t1=mod_mul(t1,ar,phiM);
        t1=mod_sub(t1,ar,phiM);
        t1=mod_add(t1,1,phiM);


        int pr_ki_power=t1;

        // res * (pr^[t1]-1)/(pr-1) %M
        int nr=power(pr,pr_ki_power);
        nr=mod_sub(nr,1);
        // cout<<"nr: "<<nr<<endl;

        int deno=mod_inverse(pr-1);     

        // (pr^[t1]-1)/(pr-1) %M
        int entire_thing=mod_mul(nr,deno);
        
        // cout<<"entire_thing: "<<entire_thing<<endl;
        res=mod_mul(res,entire_thing);
    }
    cout<<res<<endl;

}
int main()
{
    // cout<<"hello"<<endl;
    int t; cin>>t;
    // make_sieve();
    // make_max_prime();

    // cout<<sieve[10000000]<<endl;

    // cout<<"t: "<<t<<endl;
    // return 0;

    while (t--)
    {
        solve();
        /* code */
    }

    return 0;
}
