#include <bits/stdc++.h>
using namespace std;

int convert(string &word)
{
    int ans = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
        ans *= 10;
        ans += word[i] - '0';
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    
    cin.ignore();
    // map<int, vector<int>> mapping; // {Tshirt,{person ids}}
    map<pair<int,int>,bool> mapping; // {tshirt,person}->true/false
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        // cout << "s is : " << s << endl;
        stringstream obj(s);
        string word;
        while (obj >> word)
        {
            // cout << "word is: " << word << endl;
            mapping[{convert(word),i}]=true;
            // word represents Tshirt id
            // mapping[convert(word)].push_back(i);
        }
    }

    // int dp[2][(1<<n)]={0};
    vector<vector<int>> dp(101,vector<int> (1<<n));
    dp[0][0]=1; // [tshirts=0][{}]=1
    int M=1e9+7;
    for (int t_shirt = 1; t_shirt <= 100; t_shirt++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {

            // dp[TShirt=i][mask=subset of people]
            dp[t_shirt][mask] += dp[t_shirt - 1][mask];
            dp[t_shirt][mask]%=M;
            for(int bit=0;bit<n;bit++)
            {
                if(mask&(1<<bit))
                {
                    // cout<<"hello"<<endl;
                    // try to allocate t_shirt to bit
                    // check if this allocation is valid
                    // check if t_shirt has this person or not
                    // if(check())
                    if(mapping.find({t_shirt,bit})!=mapping.end())
                    {
                        int remaining_mask=mask^(1<<bit);
                        dp[t_shirt][mask]+=dp[t_shirt-1][remaining_mask];
                        dp[t_shirt][mask]%=M;
                    }
                }
            }
            
        }
    }
    cout << dp[100][(1 << n) - 1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

//  for(int person: A[i])
//             {
//                 if(mask&(1<<person))
//                 {
//                     int maskWithOutPerson=mask^(1<<person);
//                     dp[mask][i]+=dp[maskWithOutPerson][i-1];
//                     dp[mask][i]%=M;
//                 }
                
//             }