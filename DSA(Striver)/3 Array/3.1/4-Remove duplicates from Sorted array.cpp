class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1)
            return 1;
        int i=1;
        int j=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==nums[j])
                i++;
            else
            {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        // cout<<"arr";
        // for(int k=0;k<n;k++)
        // {
        //     cout<<nums[k];
        // }
        // cout<<"srr";
        return j+1;
    }
};