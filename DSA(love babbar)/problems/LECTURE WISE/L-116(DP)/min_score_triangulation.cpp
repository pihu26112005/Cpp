#include<iostream>
#include<vector>
using namespace std;

https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

/**********************************************************************************************************************************************************************************************/
// recursion
int solve (vector<int> arr , int i , int j)
{
    if(i+1==j)
        return 0;
    int mini=10000;
    for (int k = i+1; k < j; k++)
    {
        int ans = arr[i]*arr[j]*arr[k] + solve(arr,i,k) + solve(arr,k,j);
        mini = min(mini,ans);
    }
    return mini;
}

/**********************************************************************************************************************************************************************************************/
// recursion + memoization
int solve1 (vector<int> arr , int i , int j , vector<vector<int>> &dp)
{
    if(i+1==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=10000;
    for (int k = i+1; k < j; k++)
    {
        int ans = arr[i]*arr[j]*arr[k] + solve1(arr,i,k,dp) + solve1(arr,k,j,dp);
        dp[i][j] = min(dp[i][j],ans);
    }
    return dp[i][j];
}

/**********************************************************************************************************************************************************************************************/
// tubulation
int solve2 (vector<int> arr  )
{
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
    for (int i = arr.size()-1; i >=0; i--) // bottom up me top down ka ulta --> usme i bda rhe the , j ghata rhe the
    {
        for (int j = i+2; j < arr.size(); j++) // i and j ke bichme min ek element toh hona chahiye 
        {    
            dp[i][j]=10000;
            for (int k = i+1; k < j; k++)
            {
                int ans = arr[i]*arr[j]*arr[k] + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j],ans);
            }
        }   
    }
    return dp[0][arr.size()-1];
}

// space optimization not possible but try out read mcm pattern , gap strategy 
