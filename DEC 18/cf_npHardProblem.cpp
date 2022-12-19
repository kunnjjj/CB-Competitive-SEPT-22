#include<bits/stdc++.h>
using namespace std;
vector<int> graph[(int)1e5+1];
vector<int> color((int)1e5+1);
bool dfs(int root,int col)
{
    color[root]=col;
    for(int nbr:graph[root])
    {
        if(color[nbr]==0)
        {
           bool good=dfs(nbr,3-col);
           if(!good) return false;
        }
        else 
        {
            if(color[nbr]==color[root]) return false;
        }
    }
    return true;
}
int main()
{

    int n; cin>>n;
    int m; cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    

    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            bool good=dfs(i,1);
            if(!good)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    vector<int> v1,v2;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==1) v1.push_back(i);
        else v2.push_back(i);
    }
    cout<<(int)v1.size()<<endl;
    for(int x:v1) cout<<x<<" ";
    cout<<endl;
    cout<<(int)v2.size()<<endl;
    for(int x:v2) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}