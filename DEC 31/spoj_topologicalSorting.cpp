#include<bits/stdc++.h>
using namespace std;
 
vector<int> graph[(int)1e4+1];
vector<int> indegree((int)1e4+1);
int main()
{
    int n,m; cin>>n>>m;
 
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }  
     
    for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
 
    vector<int> topoSort;
    queue<int> q;
 
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
 
    while(!q.empty())
    {
        int cur_task=q.front();
        q.pop();
        topoSort.push_back(cur_task);
 
        for(int nbr:graph[cur_task])
        {
            // --indegree[nbr];
            if(--indegree[nbr]==0) q.push(nbr);
        }
    }
 
    if((int)topoSort.size() < n)
    {
        cout<<"Sandro fails."<<endl;
    }   
    else
    {
        for(int task:topoSort) cout<<task<<" ";
    }
 
    return 0;
} 