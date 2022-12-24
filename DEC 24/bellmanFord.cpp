#include <bits/stdc++.h>
using namespace std;

// struct compare
// {
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
//     {
//         return a.second < b.second;
//     }
// };

vector<pair<int, int>> graph[100];

void bellmanFord(int src, int V, vector<vector<int>> &edges)
{
    int inf = 1e9;
    vector<int> dist(V + 1, inf);
    // set<pair<int,int>,compare> s2;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (vector<int> &edge : edges)
        {
            int a = edge[0], b = edge[1], wt = edge[2];
            // flag leke can be optimised further
            dist[a] = min(dist[a], wt + dist[b]);
            dist[b] = min(dist[b], wt + dist[a]);
        }
    }

    for (vector<int> &edge : edges)
    {
        int a = edge[0], b = edge[1], wt = edge[2];
        if ((dist[b] + wt < dist[a]) || (dist[a] + wt < dist[b]))
        {
            cout << "Neg wt cycle exists" << endl;
            return;
        }
    }

    for (int i = 1; i <= V; i++)
    {
        cout << "node: " << i << ", dist: " << dist[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({a, b, wt});
    }

    bellmanFord(1, n, edges);

    return 0;
}
