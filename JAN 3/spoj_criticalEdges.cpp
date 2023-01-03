#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
vector<int> graph[(int)701];
vector<int> tin(701);
vector<int> visited(701);
vector<int> low(701);

void dfs(int node,int par,int &time)
{
    tin[node]=time++;
    low[node]=tin[node];
    visited[node]=true;

    for(int nbr:graph[node])
    {
        if(nbr==par) continue;
        if(visited[nbr]) // ancestor 
        {
            low[node]=min(low[node],tin[nbr]);
        }   
        else // if unvisited then it is normal nbr
        {
            dfs(nbr,node,time);
            if(tin[node] < low[nbr])
            {
                ans.push_back({min(node,nbr),max(node,nbr)});
            }
            low[node]=min(low[node],low[nbr]);
        }
    }
}

int main()
{
    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Caso #"<<i<<endl;
        int n,m; cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            graph[i].clear();
            visited[i]=0;
            tin[i]=0;
            low[i]=0;
        }
        
        ans.clear();
        for(int i=0;i<m;i++)
        {
            int a,b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }   
        int timer=0;
        dfs(1,-1,timer);

        if(ans.empty())
        {
            cout<<"Sin bloqueos"<<endl;
        }
        else
        {
            cout<<(int)ans.size()<<endl;
            sort(ans.begin(),ans.end());
            for(pair<int,int> p:ans) cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;
}