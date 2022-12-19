#include<bits/stdc++.h>
using namespace std;

vector<int> graph[(int)3e5+10];
vector<int> freq((int)3e5+10);
vector<int> color((int)3e5+10);

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
void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) 
    {
        graph[i].clear();
        freq[i]=0;
        color[i]=0;
    }

    bool bad=false;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(a==b)
        {
            bad=true;
        }
        freq[a]++;
        freq[b]++;
        if(max(freq[a],freq[b])>=3) bad=true;
    }

    if(bad==true)
    {
        cout<<"NO"<<endl;
        return ;
    }
    // freq <=2 , no domino of type {x,x}
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            bool good=dfs(i,1);
            if(good==false)
            {
                cout<<"NO"<<endl;
                return ;
            }
        }
    }

    cout<<"YES"<<endl;

}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}