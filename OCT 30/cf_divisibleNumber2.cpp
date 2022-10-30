#include<bits/stdc++.h>
using namespace std;


vector<long long> get_factors(long long n)
{
    vector<long long> factors;
    for(long long i=1;(1LL*i*i)<=n;i++)
    {
        if(n%i==0)
        {
            factors.push_back(i);
            long long otherFactor=n/i;
            if(i!=otherFactor)
            factors.push_back(otherFactor);
        }
    }
    return factors;
}
void solve()
{
    long long a,b,c,d; cin>>a>>b>>c>>d;

    vector<long long> factA=get_factors(a);
    vector<long long> factB=get_factors(b);

    
    for(long long p:factA)
    {
        for(long long z:factB)
        {
            long long mulX=(p*z);
            long long mulY=(a * b)/mulX;

            long long poss_x=(c/mulX) * mulX;
            long long poss_y=(d/mulY) * mulY; 
            if(a<poss_x && poss_x<=c)
            {
                if(b<poss_y && poss_y<=d)
                {
                    cout<<poss_x<<" "<<poss_y<<endl;
                    return ;
                }
            }
            mulY=(p*z);
            mulX=(a * b)/mulY;
            poss_x=(c/mulX) * mulX;
            poss_y=(d/mulY) * mulY; 
            if(a<poss_x && poss_x<=c)
            {
                if(b<poss_y && poss_y<=d)
                {
                    cout<<poss_x<<" "<<poss_y<<endl;
                    return ;
                }
            }
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


    // long long ans=1e9;
    // for(int x:factors)
    // {
    //     // har segment ka sum=x
    //     int get=func(A,x);
    //     ans=min(ans,get);
    // }
    // cout<<ans<<endl;
 
    // for(int i=1;i*i<=sum;i++)
    // {
    //     if(sum%i==0)
    //     {
    //         // factors.push_back(i);
    //         ans=min(ans,get(A,i));
            
    //         if((sum/i)!=i)
    //         {
    //             // factors.push_back(sum/i);
    //             ans=min(ans,get(A,i));
    //         }
    //     }
    // }