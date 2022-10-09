#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            res -= res / i;
        }
    }

    if (n > 1)
    {
        res -= res / n;
    }
    return res;
}

int power(int a, int b, int M = (int)1e9 + 7)
{
    int res = 1;
    int p = a % M;

    while (b > 0)
    {
        if (b & 1)
        {
            res = (1LL * res * p) % M;
        }
        p = (1LL * p * p) % M;
        b >>= 1;
    }
    // cout<<"res: "<<res<<endl;
    return res;
}

// phi[max_n]

// for (int i = 1; i <= max_n; i++)
// {
//     phi[i] = i;
// }

// for (int i = 2; i <= max_n; i++)
// {
//     if (phi[i] == i) //  ye change nahi hua than and ye prime ko
//          i is a prime numer
//         for (int j = i; j <= max_n; j+=i)
//         {
//             phi[j] -= phi[j] / i;
//         }
// }

// phi(n) = n * (1 - 1/p1) * (1-1/p2)...

int main()
{
    int M = 1e9 + 7;

    // [a^ (b^c)]%M = [a ^ ((b^c)%phi(M))]%M

    int t;
    cin >> t;
    int phiM = phi(M);

    // int phiPhiM = phi(phiM);
    // int modInverse=power(2,phiM-1,M);
    // cout<<"phiPhiM: "<<phiPhiM<<endl;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // int newPowerOfAns = power(b, c % phiPhiM, phiM);
        int newPowerOfAns=power(b,c,phiM); // b=10^9 , c=10^9 // logC, res = [0....phiM-1] phiM-1=1e9+6
        int ans = power(a, newPowerOfAns, M);   // log phiM
        cout << ans << endl;

        /* code */
    }
    // root M  + T * log(1e9)
    return 0;
}