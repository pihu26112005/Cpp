#include<iostream>
#include<vector>
using namespace std;

// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbGIwLUNVaF9nLVpxT01BbUpWSzFLTE4tOXhZZ3xBQ3Jtc0tsUklteV9RU1NYOHI4dnlBbDBMT3ZxSjQzd1ZuYTdQZkNJVC1wMG1hd2Q3dU1qdmtmeFVUQWotd2d3RzMxMTNDbXF3cF9jdjFjNWd4dW93OWVGLUF3RDRKM0hDNlNpUU5BeFYwWTk2dUFxVkNEbnRlUQ&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fmaximum-sum-of-non-adjacent-elements_843261%3FleftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=m9-H6AUBLgY

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int solve(vector<int> arr , int n) // initial n=0
{
    if(n>=arr.size())
        return 0;
    if(n==arr.size()-1)
       return arr[arr.size()-1];
    
    int inc = arr[n] + solve(arr,n+2);
    int exc = 0 + solve(arr,n+1);

    return max(inc,exc);
}

/***********************************************************************************************************************************************************************************************************/
// recursion + memoization 
// TC=O(N),SC=O(N)+O(N)
int solve1(vector<int> arr , int n , vector<int> &dp) // initial n=0
{
    if(n>=arr.size())
        return 0;
    if(n==arr.size()-1)
       return arr[arr.size()-1];
    if(dp[n]!=-1)
       return dp[n];
    
    int inc = arr[n] + solve1(arr,n+2,dp);
    int exc = 0 + solve1(arr,n+1,dp);

    return dp[n] = max(inc,exc);
}

/***********************************************************************************************************************************************************************************************************/
// tubulation
// TC=O(N),SC=O(N)
int solve2(vector<int> arr )
{
    vector<int> dp(arr.size()+1,0);
    dp[arr.size()-1] = arr[arr.size()-1];

    for (int i = arr.size()-2; i >=0; i++)
    {
        int inc = arr[i] + dp[i+2];
        int exc = 0 + dp[i+1];
        dp[i] = max(inc,exc);
    }
    
    return dp[arr.size()-1];
}

/***********************************************************************************************************************************************************************************************************/
// space optimization
// TC=O(N),SC=O(1)
int solve3(vector<int> arr )
{
    int prev2 = 0;
    int prev = arr[arr.size()-1];
    vector<int> dp(arr.size()+2,0);
    dp[arr.size()-1] = arr[arr.size()-1];

    for (int i = arr.size()-2; i >=0; i++)
    {
        int inc = arr[i] + prev2;
        int exc = 0 + prev;
        int curr = max(inc,exc);

        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}