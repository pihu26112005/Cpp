class Solution {
    public:
        int modpow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
    
        int numSubseq(vector<int>& nums, int target) {
            const int mod = 1e9 + 7;
            int n = nums.size();
            sort(nums.begin(), nums.end());
    
            // vector<int> power(n, 1);
            // for (int i = 1; i < n; ++i)
            //     power[i] = (power[i - 1] * 2) % mod;
    
            int i = 0, j = n - 1, ans = 0;
            while (i <= j) {
                if (nums[i] + nums[j] <= target) {
                    // ans = (ans + power[j - i]) % mod;
                    // ans = (ans + pow(2,j-i)) % mod; // pow retunr a double
                    ans = (ans + modpow(2, j - i, mod)) % mod;
                    i++;
                } else {
                    j--;
                }
            }
    
            return ans;
        }
    };
    
    
    
    // m2- 
    // Use two pointers: left (l) and right (r)
    // If nums[l] + nums[r] <= target, then all subsequences formed by keeping nums[l] and choosing any combination from nums[l+1] to nums[r] are valid.