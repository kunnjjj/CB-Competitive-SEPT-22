#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[(int)2e5+1];
vector<int> dist(2e5+1);
void solve()
{
    int n,m; cin>>n>>m;
    int inf=1e9;

    for(int i=1;i<=n;i++)
    {
        dist[i]=inf;
        graph[i].clear();
    }

    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back({b,0});
        graph[b].push_back({a,0});
    }

    for(int i=1;i+1<=n;i++)
    {
        graph[i].push_back({i+1,1});
        graph[i+1].push_back({i,1});
    }

    dist[1]=0;
    deque<pair<int,int>> q;
    q.push_back({1,0});

    while(!q.empty())
    {
        pair<int,int> best_pair=q.front();
        q.pop_front();
        int node=best_pair.first,distTillBest=best_pair.second;
        if(dist[node] < distTillBest) continue;
        for(pair<int,int> edge: graph[node])
        {
            int nbr=edge.first;
            int edWt=edge.second;
            if(distTillBest + edWt < dist[nbr])
            {
                dist[nbr]=distTillBest + edWt;
                if(edWt==0)
                {
                    q.push_front({nbr,dist[nbr]});
                }
                else
                {
                    q.push_back({nbr,dist[nbr]});
                }
            }
        }
    }
    cout<<dist[n]<<endl;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}