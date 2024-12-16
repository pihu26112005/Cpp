#include<vector>
// slightly updating approach for 2nd approavh of p-33 
// since in this elements are not distinct

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[l] < nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] >  nums[mid]) {
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            else{
                l++;
            }
        }
        return false;
    }
};