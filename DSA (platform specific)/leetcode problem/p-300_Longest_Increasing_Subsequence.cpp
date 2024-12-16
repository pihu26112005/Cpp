class Solution {
public:

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

    int lengthOfLIS(vector<int>& arr) {

        vector<vector<int>> dp(arr.size()+1, vector<int> (arr.size()+1,0));
        // return solve1(arr.size(),arr,-1,0,dp)
        for (int prev = arr.size()-1; prev >=-1; prev--)
        {
            for (int curr = prev+1 ; curr < arr.size(); curr++)
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
};