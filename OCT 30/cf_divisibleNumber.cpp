#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b,c,d; cin>>a>>b>>c>>d;


    for(long long x=a+1;x<=c;x++)
    {
        long long g=__gcd(x,a*b);

        //g jitna factor is being provided by x
        // the remaining factor should be provided by y, so it should be
        // a multiple of (a*b)/g;
        long long mul=(a*b)/g;
        long long poss_y=(d/mul) * mul;

        if(poss_y>b && poss_y<=d)
        {
            cout<<x<<" "<<poss_y<<endl;
            return ;
        }

    }
    cout<<-1<<" "<<-1<<endl;
}

int main()
{

    long long t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

