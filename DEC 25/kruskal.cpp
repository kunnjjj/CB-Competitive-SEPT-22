//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> par;
	vector<int> sz;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool comp(vector<int> &v1,vector<int> &v2)
	{
	    return v1[2] < v2[2];
	}
	int get(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = get(par[x]);
    }
    

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        par=vector<int> (V);
        sz=vector<int> (V);
        
        
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
        sort(edges.begin(),edges.end(),comp);
        
        for(int i=0;i<V;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        int ans=0;
        for(vector<int>& edge:edges)
        {
            int a=edge[0],b=edge[1],wt=edge[2];
            int par_a=get(a);
            int par_b=get(b);
            if(par_a!=par_b) // if they were equal it would mean on addition of this edge cycle gets formed
            { // we will avoid that, so consider the case only when par_a!=par_b
                if(sz[par_a] > sz[par_b]) swap(par_a,par_b);
                
                par[par_a]=par_b;
                sz[par_b]+=sz[par_a];
                ans+=wt; // this edge is considered in min spanning tree
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


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