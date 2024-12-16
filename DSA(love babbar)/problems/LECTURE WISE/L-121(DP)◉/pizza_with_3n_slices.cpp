#include<iostream>
#include<vector>
using namespace std;

int solve(int index , int endingindex , vector<int> slicesValue , int n) // basically main teen hi slice khaunga toh tension ki koi jarurat nhi 
{
    if(n==0 || index>endingindex)
        return 0;

    int include = slicesValue[index]+solve(index+2,endingindex,slicesValue,n-1);
    int exclude = 0+solve(index+1,endingindex,slicesValue,n);
    return max(include,exclude);
}

int maxValue(vector<int> slicesValue)
{
    int k = slicesValue.size();
    int case1 = solve(0,k-2,slicesValue,k/3);
    int case2 = solve(1,k-1,slicesValue,k/3);
    return max(case1,case2);
}
/********************************************************************************************************************************************************************************************/
// recursion + memoization
int solve1(int index , int endingindex , vector<int> slicesValue , int n , vector<vector<int>> &dp) // basically main teen hi slice khaunga toh tension ki koi jarurat nhi 
{
    if(n==0 || index>endingindex)
        return 0;
    if(dp[index][n]!=-1)
        return dp[index][n];

    int include = slicesValue[index]+solve1(index+2,endingindex,slicesValue,n-1,dp);
    int exclude = 0+solve1(index+1,endingindex,slicesValue,n,dp);
    return dp[index][n] = max(include,exclude);
}
int maxValue1(vector<int> slicesValue)
{
    int k = slicesValue.size();
    vector<vector<int>> dp1;
    int case1 = solve1(0,k-2,slicesValue,k/3,dp1);
    vector<vector<int>> dp2;
    int case2 = solve1(1,k-1,slicesValue,k/3,dp2);
    return max(case1,case2);
}
/********************************************************************************************************************************************************************************************/
// tubulation
int solve2( int index , int endingindex , vector<int> slicesValue ) // basically main teen hi slice khaunga toh tension ki koi jarurat nhi 
{
    int k = slicesValue.size();
    vector<vector<int>> dp(k+2,vector<int> (k+2,0)); // taaki i+2 index me rhe , hum vha condition bhi lga skte the niche 
    for (int i = endingindex; i >=index; i--)
    {
        for (int j = 1; j <=k/3; j++)
        {
            int include = slicesValue[i]+dp[i+2][j-1];
            int exclude = 0+dp[i+1][j];
            dp[i][j] = max(include,exclude);
        }
    }
    return dp[0][k/3];
}
int maxValue1(vector<int> slicesValue)
{
    int k = slicesValue.size();
    vector<vector<int>> dp1;
    int case1 = solve1(0,k-2,slicesValue,k/3,dp1);
    vector<vector<int>> dp2;
    int case2 = solve1(1,k-1,slicesValue,k/3,dp2);
    return max(case1,case2);
}
/********************************************************************************************************************************************************************************************/
// space optimization
int solve2( int index , int endingindex , vector<int> slicesValue ) // basically main teen hi slice khaunga toh tension ki koi jarurat nhi 
{
    int k = slicesValue.size();
    vector<vector<int>> dp(k+2,vector<int> (k+2,0)); // taaki i+2 index me rhe , hum vha condition bhi lga skte the niche 
    vector<int> curr(k+2,0);
    vector<int> next(k+2,0);
    vector<int> next2(k+2,0);
    for (int i = endingindex; i >=index; i--)
    {
        for (int j = 1; j <=k/3; j++)
        {
            int include = slicesValue[index]+next2[j-1];
            int exclude = 0+next[j];
            curr[j] = max(include,exclude);
        }
        next2 = next;
        next = curr;
    }
    return next[k/3];
}
int maxValue1(vector<int> slicesValue)
{
    int k = slicesValue.size();
    vector<vector<int>> dp1;
    int case1 = solve1(0,k-2,slicesValue,k/3,dp1);
    vector<vector<int>> dp2;
    int case2 = solve1(1,k-1,slicesValue,k/3,dp2);
    return max(case1,case2);
}