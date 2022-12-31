#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE
// Find Height(a), Height(b) 
// jiski bhi height zyada hai utna level upar chadha do
// dono ka ek ek level kam karte jao until you reach lca

// 1: binary lifting wali table dp[i][j]: 2^jth ancestor of i
// 2: try to find that ancestor of a which is not an ancestor of b,and is at max height
// 3: parent of this node(found in step 2) is LCA

vector<int> tin((int)(2e5+1));
vector<int> tout((int)(2e5+1));
vector<int> graph[(int)2e5+1];
vector<int> parent((int)2e5+1);


void dfs(int node,int &time)
{
    tin[node]=time++;

    for(int nbr:graph[node])
    {
        dfs(nbr,time);
    }
    tout[node]=time++;
}

bool is_ancestor(int node,int anc)
{
    return tin[anc]<=tin[node] && tout[node]<=tout[anc];
}

int main()
{

    int n,q; cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        cin>>parent[i];
        graph[parent[i]].push_back(i);
    }   

    parent[1]=-1;
    int time=0;
    dfs(1,time);

    int height = 20;
    vector<vector<int>> dp(n + 1, vector<int>(height + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            if (j == 0)
                dp[i][j] = parent[i];
            else if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while(q--)
    {
        int a,b; cin>>a>>b;
        if(is_ancestor(a,b))
        {
            cout<<b<<endl;
            continue;
        }
        if(is_ancestor(b,a))
        {
            cout<<a<<endl;
            continue;
        }

        int me=a;
        for(int h=height;h>=0;h--)
        {
            if(dp[me][h]!=-1 && !is_ancestor(b,dp[me][h]))
            {
                me=dp[me][h];
            }
        }

        cout<<dp[me][0]<<endl;
    }






    return 0;
}