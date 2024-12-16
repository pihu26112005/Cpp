class Solution {
public:

    int solve1 (vector<int> obstacle , int currLane , int currPos , vector<vector<int>> &dp)
    {
    if(currPos==obstacle.size()-1)
            return 0;
        if(dp[currLane][currPos]!=-1)
            return dp[currLane][currPos];

        if(obstacle[currPos+1]!=currLane)
            return solve1(obstacle,currLane,currPos+1,dp);
        else
        {
            int ans = 1e9;
            for (int i = 1; i < 4; i++)
            {
                if (i!=currLane && obstacle[currPos]!=i)
                {
                    ans = min (ans , 1+solve1(obstacle,i,currPos,dp));
                }
                
            }
            return  dp[currLane][currPos]=ans;
        }
    }
    int minSideJumps(vector<int>& obstacle) {

        vector<vector<int>> dp(4,vector<int>(obstacle.size(),1e9));

        // return solve1(obstacles,2,0,dp);

        dp[0][obstacle.size()-1]=0;
        dp[1][obstacle.size()-1]=0;
        dp[2][obstacle.size()-1]=0;
        dp[3][obstacle.size()-1]=0;

        for(int pos=obstacle.size()-2;pos>=0;pos--)
        {
            for(int lane = 1; lane<4; lane++)
            {
                if(obstacle[pos+1]!=lane)
                    dp[lane][pos]=dp[lane][pos+1];
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i < 4; i++)
                    {
                        if (i!=lane && obstacle[pos]!=i)
                        {
                            ans = min (ans , 1+dp[i][pos+1]);
                        }
                        
                    }
                    dp[lane][pos]=ans;
                }
            }
        }

    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0])); // agar starting position ke age pathar nhi hua toab tu age badega na, but agae phle hi side me lene se sabse minimu aa rhe ho toh ...

        
    }
};