#include<bits/stdc++.h>
using namespace std;

vector<int> graph[(int)3e5+10];
vector<int> dp((int)3e5+10);
vector<int> subtree((int)3e5+10);

void dfs(int root,int par)
{
    subtree[root]=1;
    vector<int> children;
    for(int child:graph[root])
    {
        if(par==child) continue;
        dfs(child,root);
        subtree[root]+=subtree[child];
        children.push_back(child);
    }

    if((int)children.size()==1)
    {
        dp[root]=subtree[children[0]]-1;
    }
    else if((int)children.size()==2)
    {
        dp[root]=max(
            dp[children[0]] + subtree[children[1]]-1 , // let c[0] get infected save c[1]
            dp[children[1]] + subtree[children[0]]-1   // let c[1] get infected save c[0]
        );
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) 
    {
        graph[i].clear();
        dp[i]=0;
        subtree[i]=0;
    }

    for(int i=0;i+1<n;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int root=1;
    dfs(root,-1);

    cout<<dp[root]<<endl;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}