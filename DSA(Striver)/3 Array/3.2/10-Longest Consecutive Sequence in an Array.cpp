#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int, pair<int, int>> m;
        unordered_map<int, bool> n;
        int ans = -1;
        unordered_map<int,bool> e;

        for(int i=0;i<nums.size();i++)
        {
            e[nums[i]]=true;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (n[nums[i]] != true) {
                cout<<nums[i]<<" ";
                int c = 1;
                n[nums[i]]=true;
                int j=nums[i]+1;
                while(e[j]==true)
                {
                    cout<<j<<" ";
                    c++;
                    n[j]=true;
                    j++;
                }
                j=nums[i]-1;
                while(e[j]==true)
                {
                    cout<<j<<" ";
                    c++;
                    n[j]=true;
                    j--;
                }
                ans = max(ans,c);
                cout<<ans<<"naya"<<endl;
            }
        }
        return ans;
    }
};
