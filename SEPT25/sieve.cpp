#include<bits/stdc++.h>
using namespace std;
int max_n=1e6;

void sieve1()
{
    vector<int> sieve(max_n+1,1);

    sieve[0]=0;
    sieve[1]=0;

    for(int i=2;i<=max_n;i++)
    {
        if(sieve[i])
        {
            for(int j=2*i;j<=max_n;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
}

void sieve2()
{
    vector<int> sieve(max_n+1,1);

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



    return 0;
}