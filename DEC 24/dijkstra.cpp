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

void dijkstra(int src, int n)
{
    int inf = 1e9;
    vector<int> dist(n + 1, inf);
    // set<pair<int,int>,compare> s2;
    dist[src] = 0;
    set<pair<int, int>> s; // {dist[node],node}
    s.insert({dist[src], src});

    while (!s.empty()) // TODO
    {
        pair<int, int> bestPair = *(s.begin()); // {dist[node],node}
        s.erase(s.begin());
        // best pair contains node with min dist
        // value of its dist in format
        // {dist[node],node}
        int bestNode = bestPair.second;
        int distTillBestNode = bestPair.first;

        for (pair<int, int> edge : graph[bestNode])
        {
            // edge: {node,egWt}
            int nbr = edge.first, edWt = edge.second;
            if (distTillBestNode + edWt < dist[nbr])
            {
                // nbr is already available
                auto it = s.find({dist[nbr], nbr});
                if (it != s.end())
                {
                    s.erase(it);
                }
                dist[nbr] = distTillBestNode + edWt;
                s.insert({dist[nbr], nbr});

                // if(it!=s.end())
                // {
                //     s.erase(it);
                //     dist[nbr]=distTillBestNode + edWt;
                //     s.insert({dist[nbr],nbr});
                // }
                // else
                // {
                //     // nbr is absent in set
                //     dist[nbr]=distTillBestNode + edWt;
                //     s.insert({dist[nbr],nbr});
                // }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "node: " << i << ", dist: " << dist[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }

    dijkstra(1, n);

    return 0;
}
