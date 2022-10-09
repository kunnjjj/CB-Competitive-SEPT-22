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

    cout << phi(35) << endl;

    cout << phi(998244353) << endl;

    return 0;
}