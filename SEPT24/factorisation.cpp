#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
vector<int> getFactors(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            int other = n / i;
            if (other != i)
            {
                factors.push_back(other);
            }
        }
    }
    return factors;
}

vector<int> get_prime_factors(int n)
{
    vector<int> prime_factors;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            prime_factors.push_back(i);
        }
    }

    if(n>1)
    {
        prime_factors.push_back(n);
    }

    return prime_factors;
}
int main()
{

    int n;
    cin >> n;
    cout << is_prime(n) << endl;

    vector<int> factors = getFactors(n);

    for (int factor : factors)
    {
        cout << factor << " ";
    }
    cout << endl;


    vector<int> prime_factors=get_prime_factors(n);

    for(int prime:prime_factors)
    {
        cout<<prime<<" ";
    }
    cout<<endl;

    return 0;
}