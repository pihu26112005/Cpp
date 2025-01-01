#include<iostream>
#include<vector>
using namespace std;

https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


/**********************************************************************************************************************************************************************************************************************************/
// my approach   TC=O(N),SC=O(1)  Greedy Algorithm
int minCoins (vector<int> coins , int amount)
{
    int ans=0;
    for (int i = coins.size()-1; i >0; i--)
    {
        int num = amount/coins[i];
        ans = ans + num;
        amount = (amount%coins[i])*coins[i];
    }
    return ans;
}
int main()
{
    vector<int> coins = {1,2,3};
    int amount = 7;
    cout<<minCoins(coins,amount);
}

/**********************************************************************************************************************************************************************************************************************************/
// recursion  
// TC = EXPO , SC = O(N)
int mincoins(vector<int> coins , int amount)
{
    if(amount==0)
        return 0;
    if(amount<0)
        return INT64_MAX;
    
    int mini = INT64_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = mincoins(coins,amount-coins[i]);
        if(ans!=INT64_MAX)
            mini = min(mini,ans+1);  // base case se ya toh ans 0 avega ya phir intmax , toh fir bdana toh pdega 0 ko
    }
    return mini;
}

/**********************************************************************************************************************************************************************************************************************************/
// recusion + memorization 
// TC = x*n x=amount,n=coins , SC=O(x) + O(x) 
int mincoins2(vector<int> coins , int amount , vector<int> &dp)
{
    if(amount==0)
        return 0;
    if(amount<0)
        return INT64_MAX;
    if(dp[amount]!=-1)
       return dp[amount];
    
    int mini = INT64_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = mincoins2(coins,amount-coins[i],dp);
        if(ans!=INT64_MAX)
            mini = min(mini,ans+1);  // base case se ya toh ans 0 avega ya phir intmax , toh fir bdana toh pdega 0 ko
    }
    dp[amount]=mini;
    return mini;
}

/**********************************************************************************************************************************************************************************************************************************/
// tubulation 
// TC = x*n x=amount,n=coins , SC=O(x)  
int mincoins3(vector<int> coins , int amount )
{
    vector<int> dp(amount+1,INT64_MAX);
    dp[0]=0;
    
    for(int i=0;i<amount;i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT64_MAX)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[amount]==INT64_MAX)
       return -1;
    return dp[amount];
}

/**********************************************************************************************************************************************************************************************************************************/

// no space optimization 


