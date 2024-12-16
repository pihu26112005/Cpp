// tc: O(logn)
// sc: O(1)

// question --> you have to find peak element, array is sorted but except for peak elements            
                    // peak elements ke age vala bada honacahiye but vo chota hai usse 
                    // aur maine samgha ki array sorted nhi hai 

// simple binary search lgao bas, vo elements jiske age ka lement usse chota hai vo peak element hoga

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        
        int s = 0;
        int e = n - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;
            if(nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
};