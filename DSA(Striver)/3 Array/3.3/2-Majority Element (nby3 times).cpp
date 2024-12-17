class Solution {
public:
// pura fanda same hai --> moore voting algorithm , bus do count, do candidate hai 
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int cd1 = INT_MIN;
        int cd2 = INT_MIN;
        for(int i=0;i<nums.size();i++) // main aim hai cd1 != cd2 rakhna 
        {
            if(c1==0 && nums[i]!=cd2)
            {
                cd1 = nums[i];
            }
            else {
                if(c2==0 && nums[i]!=cd1)
                {
                    cd2 = nums[i];
                }
            }

            if(nums[i]==cd1)
            {
                c1++;
            }
            else
            {
                if(nums[i]==cd2)
                {
                    c2++;
                }
                else
                {
                    c1--;
                    c2--;
                }
            }
        }
        // ab do candidate aa gaye hai, but check ki ye n/3 se jyada hai ya nhi 
        c1 = 0;
        c2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==cd1)
                c1++;
            if(nums[i]==cd2)
                c2++;
        }

        int t = nums.size()/3;
        vector<int> ans;
        if(c1>t)
            ans.push_back(cd1);
        if(c2>t)
            ans.push_back(cd2);
        return ans;
    }
};