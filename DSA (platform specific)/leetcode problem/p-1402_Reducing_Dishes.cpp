class Solution {
public:

    int solve1 (vector<int> s , int index , int time , vector<vector<int>> &dp)
        {
            if(index>=s.size())
                return 0;
            if(dp[index][time]!=-1)
                return dp[index][time];

            int include = s[index]*time + solve1(s,index+1,time+1,dp);
            int exclude = 0 + solve1(s,index+1,time,dp);
            return dp[index][time]=max(include,exclude);
        }

    int maxSatisfaction(vector<int>& s) {

        sort(s.begin(),s.end());
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,0));
        // return solve1(s,0,1,dp);

        for (int index = s.size()-1; index >=0; index--)
        {
            // index position pe , agar pichli sari dishes exclude kr de , toh time minimum zero ho skta hia, and agar sab ko include kr le toh maximum "index" ho sakta hai, 
            // and yaha hum index position ke liye sare possible time nikal rhe hai  
            for (int time = index; time >=0; time--)
            {
                // time+1 --> kyokii time 0 se nhi 1 se shuru hai 
                int include = s[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
        
    }
}; 