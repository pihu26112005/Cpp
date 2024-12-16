class Solution {
public:

	https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
    int solve1 (vector<int> arr , int i , int j , vector<vector<int>> &dp)
        {
            if(i+1==j)
                return 0;
            if(dp[i][j]!=-1)
                return dp[i][j];
            dp[i][j]=10000000;
            for (int k = i+1; k < j; k++)
            {
                int ans = arr[i]*arr[j]*arr[k] + solve1(arr,i,k,dp) + solve1(arr,k,j,dp);
                dp[i][j] = min(dp[i][j],ans);
            }
            return dp[i][j];
        }
    int minScoreTriangulation(vector<int>& values) {
         vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return solve1(values,0,values.size()-1,dp);
    }
};
