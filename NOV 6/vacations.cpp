#include<bits/stdc++.h>
using namespace std;

int dp[(int)1e5+1][3];
int f(int d,int a,vector<vector<int>> &A)  
{
    //f(d,a) denotes total happiness i can get from day=d......day=n-1, on perfoming activity=a
    if(d==(int)A.size()) return 0;

    if(dp[d][a]!=-1) return dp[d][a];

    int curAns=0;
    // [....]
    for(int nextDayAct=0;nextDayAct<3;nextDayAct++)
    {
        if(nextDayAct!=a)
        {
            curAns=max(curAns,A[d][a] + f(d+1,nextDayAct,A));
        }
    }
    // curAns+=A[d][a];
    return dp[d][a]=curAns;
}

int f2(int d,int a,vector<vector<int>> &A)
{
    if(d==-1) return 0;

    int curAns=0;
    for(int nextDayAct=0;nextDayAct<3;nextDayAct++)
    {
        if(nextDayAct!=a)
        {
            curAns=max(curAns,A[d][a] + f(d-1,nextDayAct,A));
        }
    }
    return curAns;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    
    int n; cin>>n;
    vector<vector<int>> A(n,vector<int> (3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++) cin>>A[i][j];
    }

    // cout<<max({f(0,0,A),f(0,1,A),f(0,2,A)})<<endl;

    // f(d,a) denotes total value i can get from days 0...i and perfoming activity=a
    // on dth day 

    dp[(int)A.size()][0]=dp[(int)A.size()][1]=dp[A.size()][2]=0;
    

    // vector<int> dpOld(3),dpNew(3);


    // for(int d=(int)A.size()-1;d>=0;d--)
    // {
    //     for(int a=2;a>=0;a--)
    //     {
    //         // dp[d][a] denotes max value from day=d....day=n-1, and curActivity=a
    //         int curAns=0;
    //         for(int nextAct=0;nextAct<3;nextAct++)
    //         {
    //             if(a!=nextAct)
    //             {
    //                 // curAns=max(curAns,dp[d+1][nextAct]);
    //                 curAns=max(curAns,dpOld[nextAct]);
    //             }
    //         }
    //         // dp[d][a]=curAns + A[d][a];
    //         dpNew[a]=curAns + A[d][a];
    //     }
    //     dpOld=dpNew;
    // }

    // // cout<<max({dp[0][0],dp[0][1],dp[0][2]})<<endl;
    // cout<<max({dpNew[0],dpNew[1],dpNew[2]})<<endl;


    int mx1=0,mx2=0,idxOfMaxActivity=-1;
    
    for(int d=(int)A.size()-1;d>=0;d--)
    {
        int idx=-1;
        int nowMx1=0,nowMx2=0;
        for(int a=2;a>=0;a--)
        {

            int nowAns;
            if(a==idxOfMaxActivity)
            {
                nowAns=mx2 + A[d][a];
            }
            else
            {
                nowAns=mx1 + A[d][a];
            }

            if(nowAns > nowMx1)
            {
                idx=a;
                nowMx2=nowMx1;
                nowMx1=nowAns;
                continue;
            }

            if(nowAns > nowMx2)
            {
                nowMx2=nowAns;
            }
        }
        mx1=nowMx1;
        mx2=nowMx2;
        idxOfMaxActivity=idx;
        // dpOld=dpNew;
    }
    
    cout<<mx1<<endl;




    
    return 0;
}