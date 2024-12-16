#include<iostream>
#include<vector>
using namespace std;

https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbERUTEp0X05PcWhlTUNobmNlOURtRUhJbVhfZ3xBQ3Jtc0ttU3BTQ1VIa0VuMmhvRW41QU9EYjNtNlhLMmpEODVzSWVSODAwTlMxeU5hcGQ2bDc5VHEydGhoQXBZUEl2QUpaMWdxdTNjWkZDNEVtV2MxSDA5aWs5S25rbWgwQlVQcnp0a1MyR1l4ekFqeVVQaVJ6QQ&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fhouse-robber_839733%3FleftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=Fe2GeXEzWM0

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
int main()
{
    vector<int> house;
    if(house.size()==1)
        return house[0];
    vector<int> first;
    vector<int> sec;
    for (int i = 0; i < house.size(); i++)
    {
        if(i!=house.size()-1)
           first.push_back(house[i]);
        if(i!=0)
           sec.push_back(house[i]);
    }
    
    int ans = max(solve(first,0),solve(sec,0));
}

/***********************************************************************************************************************************************************************************************************/
// recursion + memoization 
// TC=O(N),SC=O(N)+O(N)
int solve(vector<int> arr , int n, vector<int> &dp) // initial n=0
{
    if(n>=arr.size())
        return 0;
    if(n==arr.size()-1)
       return arr[arr.size()-1];
    if(dp[n]!=-1)
        return dp[n];
    
    int inc = arr[n] + solve(arr,n+2,dp);
    int exc = 0 + solve(arr,n+1,dp);

    dp[n]=max(inc,exc);

    return max(inc,exc);
}


long long int houseRobber(vector<int>& house)
{
    if(house.size()==1)
        return house[0];
    vector<int> first;
    vector<int> sec;
    for (int i = 0; i < house.size(); i++)
    {
        if(i!=house.size()-1)
           first.push_back(house[i]);
        if(i!=0)
           sec.push_back(house[i]);
    }
    vector<int> dp(house.size()+1,-1);
    vector<int> dp2(house.size()+1,-1);
    
    int ans = max(solve(first,0,dp),solve(sec,0,dp2));
    return ans;
}

/***********************************************************************************************************************************************************************************************************/
// tubulation
// TC=O(N),SC=O(N)
long long solve2(vector<long long> arr )
{
    vector<long long> dp(arr.size()+1,0);
    dp[arr.size()-1] = arr[arr.size()-1];

    for (int i = arr.size()-2; i >=0; i--)
    {
        long long inc = arr[i] + dp[i+2];
        long long exc = 0 + dp[i+1];
        dp[i] = max(inc,exc);
    }
    
    return dp[0];
}

long long int houseRobber(vector<int>& house)
{
    if(house.size()==1)
        return house[0];
    vector<long long> first;
    vector<long long> sec;
    for (int i = 0; i < house.size(); i++)
    {
        if(i!=house.size()-1)
           first.push_back(house[i]);
        if(i!=0)
           sec.push_back(house[i]);
    }
    
    long long ans = max(solve2(first),solve2(sec));
    return ans;
}

/***********************************************************************************************************************************************************************************************************/
// space optimization
// TC=O(N),SC=O(1)
int solve3(vector<int> arr )
{
    int prev2 = 0;
    int prev = arr[arr.size()-1];

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

int main()
{
    vector<int> house;
    vector<int> first;
    vector<int> sec;
    for (int i = 0; i < house.size(); i++)
    {
        if(i!=house.size()-1)
           first.push_back(house[i]);
        if(i!=0)
           sec.push_back(house[i]);
    }
    
    int ans = max(solve3(first),solve3(sec));
}