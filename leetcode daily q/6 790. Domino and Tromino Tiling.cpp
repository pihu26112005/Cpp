class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        int h(int n, vector<vector<int>> &dp, int ps) {
            if (n < 0) return 0;
            if (n == 0) return 1 - ps;
    
            if (dp[n][ps] != -1) return dp[n][ps];
    
            long long t1 = 0, t2 = 0, t3 = 0;
    
            if (ps == 1) {
                t2 = h(n - 1, dp, 1) % MOD;  
                t3 = h(n - 1, dp, 0) % MOD;   
            } 
            else {
                t1 = h(n - 1, dp, 0) % MOD;   
                t2 = h(n - 2, dp, 0) % MOD;  
                t3 = (2 * h(n - 2, dp, 1)) % MOD;  
            }
    
            dp[n][ps] = (t1 + t2 + t3) % MOD;
            return dp[n][ps];
        }
    
        int numTilings(int n) {
            vector<vector<int>> dp(n + 1, vector<int>(2, -1));
            return h(n, dp, 0);
        }
    };
    
    
    // 0 --> false