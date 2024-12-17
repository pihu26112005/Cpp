// mere notes me hai ye qes 
// vaha vali approach -- pahle sare 0 starting me le aao, then sare 2 end me le aao
                        //  o(n) hi hai bas jyada baar hai 

// dutcvh flag algorithm 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,e=nums.size()-1;
        // l zero kaha dalna hia,e two kaha dalna hai, m starting se iterate krega end tak.
        while(m<=e)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1)
                m++;
            else if(nums[m]==2)
            {
                swap(nums[m],nums[e]);
                e--;
                // m++; // ye nhi ayega since age vale number abhi proces nhi hue hai, so ispe dubara check hoga 
            }
        }
    }
};