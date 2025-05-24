inplace duplicate removal krna hai, but atmost 2 duplicates allowed hai

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        if(nums.size()==2)
            return 2;
        int i = 1;
        int j = 1;
        int n = nums.size();
        if(nums[1]==nums[0]){
            j++;
            i++;
        }
        while (i < n) {
            if (nums[i] == nums[j-1])
                i++;
            else {
              bool isdo = false;
              if(i+1<n && nums[i+1]==nums[i]) isdo = true;
              if(isdo){
                nums[j]=nums[i];
                nums[j+1]=nums[i+1];
                j+=2;
                i+=2;
              }
              else{
                nums[j]=nums[i];
                j++;
                i++;
              }
            }
        }
        // cout<<"arr";
        // for(int k=0;k<n;k++)
        // {
        //     cout<<nums[k];
        // }
        // cout<<"srr";
        return j ;
    }
};