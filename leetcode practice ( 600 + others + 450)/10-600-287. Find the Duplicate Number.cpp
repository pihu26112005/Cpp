class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            // vector<int> arr = nums;
            // sort(arr.begin(), arr.end());
            // for (int i = 1; i < arr.size(); i++) {
            //     if (arr[i] == arr[i - 1])
            //         return arr[i];
            // }
            // return -1;
    
    // unexoected use 
            int slow = nums[0];
            int fast = nums[0];
    
            while (true) {
                slow = nums[slow];
                fast = nums[nums[fast]];
    
                if (slow == fast) {
                    break;
                }
            }
    
            int slow2 = nums[0];
    
            while (slow != slow2) {
                slow = nums[slow];
                slow2 = nums[slow2];
            }
    
            return slow;  
        }
    };
    
    // isme 1 to n number hai 
    // n+1 iska size hai, ek number rpeat hai 
    // let vo number ko agar 0 krde to isme 0 to n tak nnumber hai 
    // matlan nums me uske sare index hai 
    