class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
         vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int newTarget = target - nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == newTarget) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                    
                } else if (sum < newTarget) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};