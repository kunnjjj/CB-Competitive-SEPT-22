#include<bits/stdc++.h>
using namespace std;


int extendedGcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a; // gcd 
    }
    int x1,y1;
    int g=extendedGcd(b,a%b,x1,y1);

    x=y1;
    y=x1 - (a/b) * y1;
    return g;
}

int modInverse(int a,int M)
{
    int x,y;
    int g=extendedGcd(a,M,x,y);
    if(g!=1)
    {
        cout<<"Mod inverse doesnt exist "<<endl;
        return -1;
    }
    else
    {
        return (x%M + M)%M;
    }
}

int main()
{


    int x,y;
    int g=extendedGcd(110,125,x,y);
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;

    cout<<modInverse(3,7)<<endl;


    cout<<(3 * modInverse(3,7))%7<<endl;

    cout<<modInverse(3,(int)1e9+7)<<endl;
    cout<<(1LL * 3 * modInverse(3,(int)1e9+7))%((int)1e9+7)<<endl;

    return 0;
}
