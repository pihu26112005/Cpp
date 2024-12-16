class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)
            return ;
        int i=0;
        int n=nums.size();
        int j=0;
        while(i<n)
        {
            if(nums[i]!=0)
            {
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
            }
            i++;
        }
    }
};