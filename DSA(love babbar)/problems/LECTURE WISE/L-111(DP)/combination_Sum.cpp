#include<iostream>
#include<vector>
using namespace std;
// L-107 Cut Rod into segment jaisa 

https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

https://leetcode.com/problems/combination-sum/description/
https://leetcode.com/problems/combination-sum-ii/description/
https://leetcode.com/problems/combination-sum-iii/description/
https://leetcode.com/problems/combination-sum-iv/description/

/*******************************************************************************************************************************************************************************************/
// recursion
int solve(vector<int> nums , int target)
{
    if(target==0)
        return 1;
    if(target<0)
        return 0;

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans + solve(nums,target-nums[i]);
    }
    return ans ;
}

int main()
{
    vector<int> n = {1,2,5};
    int t = 5;
    cout<<solve(n,5);
}

/*******************************************************************************************************************************************************************************************/
// recursion + memoization
int solve1(vector<int> nums , int target , vector<int> &dp)
{
    if(target==0)
        return 1;
    if(target<0)
        return 0;
    if(dp[target]!=-1)
        return dp[target];

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans + solve1(nums,target-nums[i],dp);
    }
    return dp[target]==ans ;
}

/*******************************************************************************************************************************************************************************************/
// tabulation
int solve1(vector<int> nums , int target )
{
    vector<int> dp(target+1,0);
    dp[0]=1;
    for (int i = 1; i <=target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if(i-nums[j]>0)
                dp[i] = dp[i] + dp[i-nums[j]] ;
        }
    }
    return dp[target];
   
}