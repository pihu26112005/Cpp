// DP L-112 same question

class Solution {
public:

    int solve1(int n , vector<int> &dp)
    {
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];

        int mini=n;
        for (int i = 1; i*i<=n; i++)
        {
            int ans = solve1(n-(i*i),dp);
                mini = min(mini,ans+1);
        }
        return dp[n]=mini;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve1(n,dp);
    }
};