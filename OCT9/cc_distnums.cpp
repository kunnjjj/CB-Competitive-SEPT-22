#include <bits/stdc++.h>
using namespace std;

int max_n = 1e7;

vector<int> sieve(max_n + 1, 1);
vector<int> max_prime(max_n + 1, 1);
void make_sieve()
{
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i * i <= max_n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= max_n; j += i)
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



int mod_mul(long long a, long long b, int M = 1e9 + 7)
{
    a %= M;
    b %= M;
    return ((1LL * a * b) % M + M) % M;
}

int mod_add(long long a, long long b, int M = 1e9 + 7)
{
    a %= M;
    b %= M;
    return ((a + b) % M + M) % M;
}

int mod_sub(long long a, long long b, int M = 1e9 + 7)
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
        if (b & 1)
        {
            res = mod_mul(res, p);
        }
        p = mod_mul(p, p);
        b >>= 1;
    }
    return res;
}

int mod_inverse(long long a, int M = (int)1e9 + 7)
{

    int phiM = M - 1;
    a %= M;
    int inv = power(a, phiM - 1, M);
}


void solve()
{
    int n,k; cin>>n>>k;

    long long res=n;

    int M=1e9+7;
    int phiM=M-1;
    while (n>1)
    {

        int cur_prime=max_prime[n];
        int pr=cur_prime;
        int cnt=0;
        
        // cout<<"cur_prime: "<<cur_prime<<endl;
        while (n>1 && cur_prime==max_prime[n])
        {
            n/=cur_prime;
            cnt++;
            /* code */
        }
        int ar=cnt;
        // res * (pr^[[(2^k)*ar] - ar + 1)]-1)/(pr-1)

        //  find pr ^ [[(2^k)*ar] - ar + 1)] %M

        // [(2^k*ar) - ar + 1]%phiM
        // [(2^k % phiM * ar%phiM ) - ar + 1]%phiM

        int t1=power(2,k,phiM);
        t1=mod_mul(t1,ar,phiM);
        t1=mod_sub(t1,ar,phiM);
        t1=mod_add(t1,1,phiM);


        int pr_ki_power=t1;

        // res * (pr^[t1]-1)/(pr-1) %M
        int nr=power(pr,pr_ki_power);
        nr=mod_sub(nr,1);

        int deno=mod_inverse(pr-1);

        // (pr^[t1]-1)/(pr-1) %M
        int entire_thing=mod_mul(nr,deno);
        res=mod_mul(res,entire_thing);
    }
    cout<<res<<endl;
    


}
int main()
{
    int t; cin>>t;
    make_sieve();
    make_max_prime();
    while (t--)
    {
        solve();
        /* code */
    }
    

    return 0;
}
