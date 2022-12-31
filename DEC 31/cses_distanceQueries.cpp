#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> dp((int)2e5 + 1, vector<int>(19, -1));
vector<int> tin((int)2e5 + 1);
vector<int> tout((int)2e5 + 1);
vector<int> mp[(int)2e5 + 1];
vector<int> height(2e5+1);
vector<int> parent((int)2e5+1);
void dfs(int i, int par, int &time,int h)
{
    tin[i] = time++;
    height[i]=h;
    parent[i]=par;
    for (int nbr : mp[i])
    {
        if(nbr!=par)
        dfs(nbr, i, time,h+1);
    }
    tout[i] = time++;
}
 
bool is_ancestor(int u,int par)
{
    return (tin[par]<=tin[u] && tout[u]<=tout[par]);
}
 
int main()
{
    int n, q;
    cin >> n >> q;
 
    for (int i = 2; i <= n; i++)
    {
        int x,y; cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    int time = 1;
    dfs(1, -1, time,0);
 
    for(int i=1;i<=n;i++)
    dp[i][0]=parent[i];
 
    for (int j = 1; j <= 18; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    
 
    while (q--)
    {
        int x,y; cin>>x>>y;
        // cout<<"x: "<<x<<endl;
        // cout<<"y: "<<y<<endl;
        if(is_ancestor(x,y))
        {
            cout<<height[x]-height[y]<<endl;
            continue;
        }
        if(is_ancestor(y,x))
        {
            cout<<height[y]-height[x]<<endl;
            continue;
        }
        
 
        int me=x;
        
        for(int h=18;h>=0;h--)
        {
            
            if(dp[me][h]!=-1 && !is_ancestor(y,dp[me][h]))
            {
                // cout<<"me: "<<me<<endl;
                me=dp[me][h];
                // cout<<"me: "<<me<<endl<<endl;
            }
        }
        // cout<<dp[me][0]<<endl;
        int lca=dp[me][0];
        // cout<<"lca: "<<lca<<endl;
 
        cout<< (height[x] + height[y]) - 2*height[lca]<<endl;
    }
 
    return 0;
}
