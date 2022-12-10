#include<bits/stdc++.h>
using namespace std;
string k;
int d;
int M=1e9+7;

int dp[(int)1e4+1][2][100];
int count(int i,bool tight,int sum)
{
    if(i==(int)k.size())
    {
        return sum==0;
    }
    if(dp[i][tight][sum]!=-1)
    {
        return dp[i][tight][sum];
    }
    int ans=0;
    // if(tight)
    // {
    //     int digKiEntry=k[i]-'0';
    //     for(int cur_dig=0;cur_dig<=digKiEntry;cur_dig++)
    //     {
    //         if(cur_dig==digKiEntry)
    //         ans+=count(i+1,true,(sum+cur_dig)%d);
    //         else 
    //         ans+=count(i+1,false,(sum+cur_dig)%d);
    //     }
    // }
    // else
    // {
    //     for(int cur_dig=0;cur_dig<=9;cur_dig++)
    //     {
    //         ans+=count(i+1,false,(sum+cur_dig)%d);
    //     }
    // }
    
    int up=9;
    if(tight)
    {
        up=min(up,k[i]-'0'); 
    }

    for(int cur_dig=0;cur_dig<=up;cur_dig++)
    {
        ans+=count(i+1,tight&(cur_dig==up),(sum+cur_dig)%d);
        ans%=M;
    }


    return dp[i][tight][sum]=ans;
} 

int main()
{ 
     
    cin>>k>>d;
        
    memset(dp,-1,sizeof(dp));
    cout<<((count(0,true,0)-1)%M + M)%M<<endl;
    
    return 0;
}