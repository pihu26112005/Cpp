#include<iostream>
#include<vector>
using namespace std;

// not on code sutdio
// https://leetcode.com/problems/perfect-squares/

/**********************************************************************************************************************************************************************************************************************************/
// recursion
int solve(int n)
{
    if(n==0)
        return 0;

    int mini=n;
    for (int i = 1; i<=n; i++)
    {
        if((i*i)<=n)
        {
            int ans = solve(n-(i*i));
                mini = min(mini,ans+1);
        }
    }
    return mini;
}

/**********************************************************************************************************************************************************************************************************************************/
// recursion + meoization
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
int main()
{
    int n=100;
    vector<int> dp(n+1,-1);
    cout<<solve1(n,dp);
}

/**********************************************************************************************************************************************************************************************************************************/
// tabulation
int solve1(int n )
{
    vector<int> dp(1+n,n);
    dp[0]=0;
    dp[1]=1;

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i*i<=j; i++)
        {
            int ans = dp[j-(i*i)];
            dp[j] = min(dp[j],ans+1);
        }
    }
    
    return dp[n];
}