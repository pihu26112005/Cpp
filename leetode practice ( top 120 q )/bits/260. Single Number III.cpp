class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            int xorr = 0;
            for(int num : nums) {
                xorr ^= num;
            }
    
            // Safe way to get rightmost set bit
            unsigned int t = xorr & -(unsigned int)xorr;
    
            int b1 = 0, b2 = 0;
            for(int num : nums) {
                if (num & t)
                    b1 ^= num;
                else
                    b2 ^= num;
            }
    
            return {b1, b2};
        }
    };
    