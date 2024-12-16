#include<vector>

// although o(n) still fast enough, but we have to do it in o(logn)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            ans = ans^nums[i];
        }
        return ans;
    }
};