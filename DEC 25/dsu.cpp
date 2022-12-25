#include <bits/stdc++.h>

using namespace std;

class dsu
{
    int n;
    vector<int> parent;
    vector<int> sz;

public:
    dsu(int N) // {0.....n-1}
    {
        n = N;
        parent = vector<int>(n);
        sz = vector<int>(n, 1);
        init(n);
    }

    void init(int n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find_par(int x) // finds super parent
    {                   // super parent is the ancestor at topmost level
        if (x == parent[x])
        {
            return x;
        }

        // for(int nbr:graph[x]) find_par(nbr);
        return parent[x] = find_par(parent[x]);
    }

    void add_edge(int x, int y)
    {
        // given dono nodes ke super ke beech mein edge daaldete hai
        int par_x = find_par(x);
        int par_y = find_par(y);
        if(par_x!=par_y)
        {

            int size_par_x=sz[par_x];
            int size_par_y=sz[par_y];

            // convention ki size_of_par_x <= size_of_par_y
            if(size_par_x > size_par_y) swap(par_x,par_y);

            parent[par_x]=par_y;
            sz[par_y]+=sz[par_x];
            
            // if(size_par_x < size_par_y)
            // {
            //     parent[par_x]=par_y;
            //     sz[par_y]+=sz[par_x];
            // }
            // else
            // {
            //     parent[par_y]=par_x;
            //     sz[par_x]+=sz[par_y];
            // }
        }
    }

    bool query(int x, int y) // tell whether x and y are in same cc
    {
        int par_x = find_par(x);
        int par_y = find_par(y);
        return par_x == par_y;
    }
};

int main()
{
    int n = 6;
    int q;
    cin >> q;

    dsu D(n);

    for (int i = 0; i < q; i++)
    {
        // type 1 add edge
        // type 2 query ans whether they are in same cc
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            D.add_edge(x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << D.query(x, y) << endl;
        }
    }

    return 0;
}
