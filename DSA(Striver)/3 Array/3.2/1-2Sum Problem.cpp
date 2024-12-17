#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> m;
        m[nums[0]]=1;
        for(int i=1;i<nums.size();i++)
        {
            int no = t-nums[i];
            if(m[no]!=0)
            {
                return {m[no]-1,i};
            }
            m[nums[i]]=i+1;
        }
        return {};
    }
};

