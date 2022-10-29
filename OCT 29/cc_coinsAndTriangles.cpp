#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // while (t--)
    // {

    //     int n;
    //     cin >> n;
    //     int s = 1, e = n;
    //     int ans = 0;
    //     while (s <= e)
    //     {
    //         int mid = (s + e) / 2;

    //         long long coins = (mid * 1LL * (mid + 1)) / 2;
    //         if (n >= coins)
    //         {
    //             ans = mid;
    //             s = mid + 1;
    //         }
    //         else
    //         {
    //             e = mid - 1;
    //         }
    //     }
    //     cout << ans << endl;
    // }

    while (t--)
    {

        int n;
        cin >> n;
        int s = 0, e = n+1;
        
        while (e-s>1)
        {
            int mid = (s + e) / 2;

            long long coins = (mid * 1LL * (mid + 1)) / 2;
            if (n >= coins)
            {
                s=mid;
            }
            else
            {
                e = mid;
            }
        }
        cout << s << endl;
    }

    return 0;
}
