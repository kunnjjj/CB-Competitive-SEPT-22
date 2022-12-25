#include <bits/stdc++.h>
using namespace std;

vector<int> par((int)1e5 + 1);
vector<int> sz((int)1e5 + 1);

int get(int x)
{
    if (x == par[x])
        return x;
    return par[x] = get(par[x]);
}

void merge(int x, int y)
{
    int par_x = get(x);
    int par_y = get(y);
    if (par_x != par_y)
    {
        // size of par_x is always smaller
        if (sz[par_x] > sz[par_y])
            swap(par_x, par_y);

        par[par_x] = par_y;
        sz[par_y] += sz[par_x];
    }
}

int query(int x)
{
    // return sz[get(x)];
    int par_x = get(x);
    return sz[par_x];
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < q; i++)
    {
        char type;
        cin >> type;
        if (type == 'M')
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }

    return 0;
}
