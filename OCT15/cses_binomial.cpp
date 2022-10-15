#include <bits/stdc++.h>
using namespace std;

int extendedGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a; // gcd
    }
    int x1, y1;
    int g = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
int modInverse(int a, int M)
{
    int x, y;
    int g = extendedGcd(a, M, x, y);
    if (g != 1)
    {
        cout << "Mod inverse doesnt exist " << endl;
        return -1;
    }
    else
    {
        return (x % M + M) % M;
    }
}

int main()
{
    int max_n = 1e6;
    vector<int> fact(max_n + 1);
    vector<int> inv_fact(max_n + 1);
    fact[0] = 1;
    int M = 1e9 + 7;

    for (int i = 1; i <= max_n; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % M;
    }

    inv_fact[max_n] = modInverse(fact[max_n], M);

    for (int i = max_n - 1; i >= 0; i--)
    {
        // inv_fact[i]=(1LL * (i+1) * inv_fact[i+1])%M;
        inv_fact[i] = modInverse(fact[i], M);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        int nr = fact[n];
        // cout<<"nr: "<<nr<<endl;
        int dn = (1LL * inv_fact[r] * inv_fact[n - r]) % M;
        // cout<<"dr: "<<dn<<endl;
        cout << (1LL * nr * dn)%M << endl;
    }

    return 0;
}