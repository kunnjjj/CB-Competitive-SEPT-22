#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>


using namespace std;
vector<int> graph[100];
int n,m; 
void breadthFirstSearch(int src)
{
    // every node is pushed at max 1 time
    // 1 time popped
    // every edge is travesed by the two end pts only
    // O(2*N + 2*M)= O(N+M)
    vector<bool> visited(n+1);
    queue<int> q;
    // push all src
    q.push(src);
    visited[src]=true;
    // centre[src]=src;

    while (!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(int nbr:graph[node])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr]=1;
                // centre[nbr]=centre[node];
            }
        }
    }
    cout<<endl;
}
void dfs(int node,vector<int>&visited) // O(N+M)
{
    // function is called for every node at max 1 time
    // every edge is travesed by the two end pts only
    // O(N + 2*M)= O(N+M)
    cout<<node<<" ";
    visited[node]=true;
    for(int nbr:graph[node])
    {
        if(!visited[nbr])
        {  
            dfs(nbr,visited);
        }
    }

}
int main()
{
    cin>>n>>m; // 1......N

    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    int src=1;
    breadthFirstSearch(src);
    vector<int> visited(n+1);
    // dfs(1,visited);
    int comp=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            comp++;
            dfs(i,visited);
            cout<<endl;
        }
    }
    cout<<"comp: "<<comp<<endl;




    return 0;
}