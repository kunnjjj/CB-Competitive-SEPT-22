#include <bits/stdc++.h>
using namespace std;
long long dp[19][2][2][11];
long long count(int idx, int tight, int leadingZero,int last_dig, string &s)
{
    if (idx == (int)s.size())
    {
        return 1;
    }

    long long &ret = dp[idx][tight][leadingZero][last_dig];

    if (ret != -1)
        return ret;

    

    long long ans = 0;
    int up = 9;
    if (tight)
    {
        up = min(up, s[idx] - '0');
    }

    for (int cur_dig = 0; cur_dig <= up; cur_dig++)
    {
        if(cur_dig != last_dig or (cur_dig==0 && leadingZero))
        {
            ans += count(idx + 1, tight&(cur_dig==up), leadingZero&(cur_dig==0),cur_dig, s);
        }
    }
    return ret = ans;
}
int main()
{
    long long L, R;
    cin >> L >> R;

    string s = to_string(R);
    memset(dp, -1, sizeof(dp));
    long long R_ans = count(0, true,true, 10, s);
    long long Lminus1_ans = 0;

    if (L >= 1)
    {
        s = to_string(L - 1);

        memset(dp, -1, sizeof(dp));
        Lminus1_ans = count(0, true,true, 10, s);
    }

    cout << (R_ans - Lminus1_ans) << endl;
    return 0;
}