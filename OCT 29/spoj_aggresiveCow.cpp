#include <bits/stdc++.h>
using namespace std;

bool is_possible_to_place(vector<int> &A, int C, int minDist)
{
    C--;
    int reqdCoOrdinate = A[0] + minDist;
    for (int i = 1; i < (int)A.size() && C>0; i++)
    {
        if (A[i] >= reqdCoOrdinate)
        {
            C--;

            reqdCoOrdinate = A[i] + minDist;
        }
    }
    return (C==0);
}
void solve()
{

    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    // int ans = 0;

    // for (int min_dist = 1; min_dist <= A[n - 1]; min_dist++)
    int s=0,e=A[n-1]-A[0] + 1;
    while(e-s>1)
    {
        int min_dist=(s+e)/2;
        if (is_possible_to_place(A, c, min_dist))
        {
            s=min_dist;
        }
        else
        {
            e=min_dist;
        }
    }
    cout << s << endl;
}
int main()
{
    int t; cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    

    return 0;
}