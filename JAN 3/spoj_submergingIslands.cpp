#include <bits/stdc++.h>
using namespace std;
set<int> ans;
vector<int> graph[(int)(int)1e5+1];
vector<int> tin((int)1e5+1);
vector<int> visited((int)1e5+1);
vector<int> low((int)1e5+1);

void dfs(int node, int par, int &time)
{
    tin[node] = time++;
    low[node] = tin[node];
    visited[node] = true;

    int children = 0;
    for (int nbr : graph[node])
    {
        if (nbr == par)
            continue;
        if (visited[nbr]) // ancestor
        {
            low[node] = min(low[node], tin[nbr]);
        }
        else // if unvisited then it is normal nbr
        {
            children++;
            dfs(nbr, node, time);
            if (par!=-1 && tin[node] <= low[nbr])
            {
                ans.insert(node);
            }
            low[node] = min(low[node], low[nbr]);
        }
    }
    if (par == -1 && children >= 2) // children mean distinct cc 
    {
        ans.insert(node);
    }
}

int main()
{

    for (int i = 1; true; i++)
    {
        // cout<<"Caso #"<<i<<endl;
        int n, m;
        cin >> n >> m;
        if (n == 0 || m == 0)
            return 0;

        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
            visited[i] = 0;
            tin[i] = 0;
            low[i] = 0;
        }

        ans.clear();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int timer = 0;
        dfs(1, -1, timer);
        cout << ans.size() << endl;
    }
    return 0;
}