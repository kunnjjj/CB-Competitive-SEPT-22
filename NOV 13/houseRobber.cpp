class Solution {
public:
    int rob(vector<int>& A) {
         
        int n=A.size();
        vector<vector<int>> dp(n+3,vector<int> (2));
        
        for(int i=n-1;i>=0;i--)
        {
            // dp[i][0] ith-take, and some in i+2...
            
            
            dp[i][0]=A[i] + max(dp[i+2][0],dp[i+2][1]);
            
            // dp[i][1] ith house not taken
            dp[i][1]=max(dp[i+1][0],dp[i+1][1]);
        }
        return max(dp[0][0],dp[0][1]);
    }
};