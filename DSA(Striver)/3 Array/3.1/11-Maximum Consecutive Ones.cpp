class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int temp = 0;

        while (i < nums.size()) {
            if (nums[i] == 1) {
                // Count consecutive ones
                while (i < nums.size() && nums[i] == 1) {
                    temp++;
                    i++;
                }
                ans = max(ans, temp);
                temp = 0;
            } else {
                i++; // Move to the next element if it's not 1
            }
        }
        return ans;
    }
};
