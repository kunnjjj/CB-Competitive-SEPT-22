#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);

    for (int i = 2; i <= n; i++)
        cin >> parent[i];

    parent[1] = -1;
    int height = 20;
    vector<vector<int>> dp(n + 1, vector<int>(height + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            if (j == 0)
                dp[i][j] = parent[i];
            else if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }


    while(q--)
    {
        int node,k; cin>>node>>k;

        int me=node;
        for(int h=height;h>=0 && me!=-1;h--)
        {
            if(k&(1<<h))
            {
                me=dp[me][h];
            }
        }
        cout<<me<<endl;
    }

    return 0;
}