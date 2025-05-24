// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]

class Solution {
public:
    int removeElement(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int i=0;
        int j=nums.size()-1;
        while(j>=0 && nums[j]==k) j--;
        int ans = 0;
        while(i<j){
            if(nums[i]==k){
                // ans++;
                nums[i] = nums[i]^nums[j];
                nums[j] = nums[i]^nums[j];
                nums[i] = nums[i]^nums[j];
                // j--;
                while(j>=0 && nums[j]==k) j--;
                i++;
            }
            else{
                i++;
            }
        }
        for(int i:nums) if(i!=k) ans++; 
        return ans;
    }
};