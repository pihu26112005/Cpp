class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int l=0;
        int sm=0;
        int ans=100000000;
        for(int r=0;r<nums.size();r++){
            sm+=nums[r];
            while(sm>=t){
                ans=min(ans,r-l+1);
                sm-=nums[l];
                l++;
            }
        }
        return ans==100000000 ? 0 : ans;
    }
};