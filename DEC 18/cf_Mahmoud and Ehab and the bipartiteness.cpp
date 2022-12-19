#include<bits/stdc++.h>
using namespace std;
vector<int> graph[(int)1e5+1];
vector<int> color((int)1e5+1);
void dfs(int root,int par,int col)
{
    color[root]=col;
    for(int nbr:graph[root])
    {
        if(nbr!=par)
        {
            dfs(nbr,root,1-col);
        }
    }
}
int main()
{

    int n; cin>>n;
    for(int i=0;i+1<n;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,-1,1);
    long long ones=0,zeros=0;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0) zeros++;
        else ones++;
    }
    cout<<ones *zeros - (n-1)<<endl;
    
    return 0;
}