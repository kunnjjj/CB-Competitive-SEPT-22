//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<vector<int>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<(int)adj[i].size();j++)
            {
                // adj[i][j]={u,wt}
                int u=adj[i][j][0];
                int wt=adj[i][j][1];
                if(i < u)
                edges.push_back({i,u,wt});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> visited(V);
        // V-1
        for(int j=0;j<(int)adj[V-1].size();j++)
        {
            int u=adj[V-1][j][0];
            int wt=adj[V-1][j][1];
                
            pq.push({wt,u});
        }
        visited[V-1]=true;
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int> edge=pq.top();
            pq.pop();
            
            int node=edge.second,wt=edge.first;
            if(visited[node]) continue;
            visited[node]=true;
            ans+=wt;
            for(int j=0;j<(int)adj[node].size();j++)
            {
               int u=adj[node][j][0];
                int wt=adj[node][j][1];
                if(!visited[u])
                pq.push({wt,u}); 
            }
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
// for(int i=1;i<=n;i++)
// {
//     if(!visited[i])
//     {
//         applyPrims(i);
//     }
// }


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends