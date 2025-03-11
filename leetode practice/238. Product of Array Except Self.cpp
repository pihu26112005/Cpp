class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p = 1;
        int nzero = 0;
        for (int i : nums) {
            if (i == 0)
                nzero++;
            else
                p *= i;
        }
        if (nzero > 1) {
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(0);
            }
        }
        else if(nzero == 1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0) ans.push_back(p);
                else ans.push_back(0);
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans.push_back(p/nums[i]);
            }
        }
        return ans;
    }
};