class Solution {
public:
    vector<int> dp;
    // map<pair<int,int>,bool> is_pal;
    vector<vector<int>> is_pal;
    int f(int i)
    {
        // f(i) denotes min cuts to cut s[0...i] into palindromes
        // ans=f(n-1)
        
        if(dp[i]!=-1) return dp[i];
        int myAns=1e9;
        
        for(int j=i;j>=0;j--)
        {
            // if(is_pal.find({j,i})!=is_pal.end())
            if(is_pal[j][i])
            {
                int cur_ans;
                if(j==0)
                {
                    cur_ans=0;
                }
                else
                {
                    cur_ans= 1 + f(j-1);
                }
                myAns=min(myAns,cur_ans);
            }
                
        }
        return dp[i]=myAns;
    }
    int minCut(string s) {
        int n=s.size();
        dp=vector<int> (n+1,-1);
        is_pal=vector<vector<int>> (n+1,vector<int> (n+1));
        // is_pal[L][R]=0; s[L...R] isnt palin
        // else is_pal
        
        // for(int centre=0;centre<n;centre++)
        // {
        //     int L=centre,R=centre;
        //     while(L>=0 && R<n && s[L]==s[R])
        //     {
        //         is_pal[{L,R}]=true;
        //         L--;
        //         R++;
        //     }
        //     L=centre,R=centre+1;
        //     while(L>=0 && R<n && s[L]==s[R])
        //     {   
        //         is_pal[{L,R}]=true;
        //         L--;
        //         R++;
        //     }
        // }
        for(int L=n-1;L>=0;L--)
        {
            for(int R=L;R<n;R++)
            {
                // s[L....R]
                // is_pal[L..R]
                if(s[L]!=s[R])
                {
                    is_pal[L][R]=0;
                }
                else
                {
                    is_pal[L][R]=(L+1<=R-1?is_pal[L+1][R-1]:1);
                }

            }
        }
        
        
        f(n-1);
        
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};