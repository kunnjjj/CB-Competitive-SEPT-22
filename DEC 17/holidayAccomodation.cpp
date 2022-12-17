#include<bits/stdc++.h>
using namespace std;

// visited global
// graph global

int n,m;
const int MAX_N=1e5;
vector<pair<int,int>> graph[MAX_N+1];

int dfs(int root,int par,long long &ans)
{
    int mySize=1;
    for(pair<int,int> Edge: graph[root])
    {
        if(Edge.first!=par)
        {
            int subtreeSize=dfs(Edge.first,root,ans);
            mySize+=subtreeSize;
            int travelled=min(subtreeSize,n-subtreeSize) * 2;
            ans+=(travelled * 1LL * Edge.second);
        }
    }
    return mySize;
}

void solve()
{
    cin>>n;
    int m=n-1;
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
    }

    for(int i=0;i<m;i++)
    {
        int a,b,wt; cin>>a>>b>>wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"node: "<<i<<endl;
    //     cout<<"nbrs: "<<endl;
    //     for(pair<int,int> edge:graph[i])
    //     {
    //         cout<<edge.first<<" "<<edge.second<<endl;
    //     }
    // }
    long long ans=0;
    dfs(1,-1,ans);
    cout<<ans<<endl;
    
}
int main()
{

    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }



    return 0;
}