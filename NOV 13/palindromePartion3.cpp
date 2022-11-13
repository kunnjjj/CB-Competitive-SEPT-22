class Solution {
public:
    int palindromePartition(string s, int k) {
        int n=s.size();
        
        int inf=1e9;
        vector<vector<int>> dp(n+1,vector<int> (k+1,inf));
        
        vector<vector<int>> minChanges(n+1,vector<int> (n+1));
        
        for(int centre=0;centre<n;centre++)
        {
            int L=centre,R=centre;
            int op=0;
            while(L>=0 && R<n )
            {
                
                // is_pal[{L,R}]=true;
                if(s[L]==s[R])
                {

                }
                else
                {
                    op++;
                }
                minChanges[L+1][R+1]=op;
                L--;
                R++;
            }
    
            op=0;
            L=centre,R=centre+1;
            while(L>=0 && R<n )
            {   
                if(s[L]==s[R])
                {

                }
                else
                {
                    op++;
                }
                minChanges[L+1][R+1]=op;
                L--;
                R++;
            }
        }
        // dp[0][0]=0; empty string with 0 partion requires 0 cost
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int x=1;x<=k;x++)
            {
                // dp[i][x] min changes
                // s[0...i] with x partitions
                for(int j=i;j>=1;j--)
                {
                    int min_changes= minChanges[j][i]; //min_changes to makes[j..i] into a palindrome; //TODO
                    int pos_ans=min_changes + dp[j-1][x-1];
                    dp[i][x]=min(dp[i][x],pos_ans);
                }
                
            }
        }
        return dp[n][k];     
    }
};