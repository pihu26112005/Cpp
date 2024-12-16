#include<iostream>
#include<vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// leeetcode 
// https://leetcode.com/problems/longest-increasing-subsequence/
/**********************************************************************************************************************************************************************************************/
// recursion
int solve(int n , vector<int> arr , int prev , int curr)  // initial time should be 1 
{
    if(curr==n)
        return 0;
    int exclude = solve(n,arr,prev,curr+1);
    int include;
    if(prev==-1 || arr[curr]>arr[prev])
        include = 1 + solve(n,arr,curr,curr+1);
    else
        include = solve(n,arr,prev,curr+1);
    
    return max(include,exclude);
}

/**********************************************************************************************************************************************************************************************/
// recursion + memoization
 int solve1(int n , vector<int> arr , int prev , int curr , vector<vector<int>> &dp)  
    {
        // prev -1 ho sakta hai isiliye hum , prev ki jagah har jagah prev+1 hi use kr rhe hai 
        if(curr==n)
            return 0;
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        int exclude = solve1(n,arr,prev,curr+1,dp);
        int include=-1;
        if(prev==-1 || arr[curr]>arr[prev])
            include = 1 + solve1(n,arr,curr,curr+1,dp);
        else
            include = solve1(n,arr,prev,curr+1,dp);
        
        dp[curr][prev+1] = max(include,exclude);
        return max(include,exclude);
    }


/**********************************************************************************************************************************************************************************************/
// tubulation
int solve2(int n , vector<int> arr )  
{
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for (int curr = n-1 ; curr >=0; curr--)
    // main variable curr hai 
    { 
        for (int prev = curr-1; prev >=-1; prev--)
        {
            int exclude = dp[curr+1][prev+1];
            int include;
            if(prev==-1 || arr[curr]>arr[prev])
                include = 1 + dp[curr+1][curr+1];
            else
                include = dp[curr+1][prev+1];
            
            dp[curr][prev+1]= max(include,exclude);
        }
    }
    return dp[0][0];
}
/**********************************************************************************************************************************************************************************************/
// space optimization
int solve3(int n , vector<int> arr )  
{
    vector<int> next(n+1,0);
    vector<int> current(n+1,0);
    for (int curr = n-1 ; curr >=0; curr--)
    { 
        for (int prev = curr-1; prev >=-1; prev--)
        {
            int exclude = next[prev+1];
            int include;
            if(prev==-1 || arr[curr]>arr[prev])
                include = 1 + next[curr+1];
            else
                include = next[prev+1];
            
            current[prev+1]= max(include,exclude);
        }
        next = current;
    }
    return current[0];
}
/**********************************************************************************************************************************************************************************************/
// dp with binary search
int solve3(int n , vector<int> arr )  
{
    if(n==0)
        return 0;
    vector<int> ans ;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>ans.back())
            ans.push_back(arr[i]);
        else
        {
            // find indexx of just greater element 
            int index = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin(); // this is binary search 
            // lower bound sirf position iterator deta hai, we need to subtract from begin to get index
            ans[index]=arr[i];
        }
    }
    return ans.size();
}