// https://leetcode.com/problems/sum-of-distances-in-tree/description/

class Solution {
public:
    vector<int> graph[(int)3e4+1];
    vector<int> dp,subtree,ans;

    int N;
    void dfs1(int root,int par)
    {
        subtree[root]=1;
        for(int nbr:graph[root])
        {
            if(nbr!=par)
            {
                dfs1(nbr,root);
                dp[root]+=dp[nbr] + subtree[nbr];
                subtree[root]+=subtree[nbr];
            }
        }
    }
    void dfs2(int root,int par)
    {
        if(par!=-1)
        {
            ans[root]=ans[par]- 2* subtree[root] + N;
        }
        for(int nbr:graph[root])
        {
            if(nbr==par) continue;
            dfs2(nbr,root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<(int)edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        ans=vector<int> (n);
        dp=vector<int> (n);
        subtree=vector<int> (n);
        N=n;

        int root=0;
        dfs1(root,-1);
        ans[root]=dp[root];
        dfs2(root,-1);
        return ans;
    }
};