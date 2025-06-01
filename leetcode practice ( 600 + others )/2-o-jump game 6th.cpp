// https://leetcode.com/problems/jump-game-vi/description/
class Solution {
    public:
        int maxResult(vector<int>& nums, int k) {
             int n = nums.size();
            vector<int> dp(n);
            dp[0] = nums[0];
            deque<int> dq;
            dq.push_back(0);
            
            for (int i = 1; i < n; ++i) {
                // i ke liye useful hai i-k to i-1 (fron to back)
                // hum inme se dcreasing order vale hi rakh rhe hai 
                if (dq.front() < i - k) dq.pop_front(); // agar pahla index not use ful for i
                
                dp[i] = nums[i] + dp[dq.front()];
                
                while (!dq.empty() && dp[i] >= dp[dq.back()])
                    dq.pop_back();
                // dp[i] end me jayega, isse pahle isse bada ana chahiye 
                
                dq.push_back(i);
            }
            
            return dp[n - 1];
        }
    };
    // isme deque me --> numbers ka decreasing order hai from front to back 
    // but index ka increasing order hai from front to back 
    
    // the two directions are:
    // Forward thinking (what’s reachable next): → i + 1 to i + k
    // Backward thinking (who can reach here): → i - k to i - 1
    
    
    // isme overlapping ho rhi hai 
    // dp[i] --> i+1,i+2,i+3,i+4
    // dp[i-1] --> i,i+1,i+2,i+3
    // isme teen calls overlap kr rhi hai 