// https://leetcode.com/problems/jump-game-iii/description/
class Solution {
    public:
        bool h(vector<int> &arr, int i, vector<int> &vis){
            if(i<0 || i>=arr.size())   
                return false;
            if(arr[i]==0)
                return true;
            if(vis[i]==1)
                return false;
            vis[i]=1;
            bool ans1 = h(arr,i+arr[i], vis);
            bool ans2 = h(arr,i-arr[i], vis);
            return ans1||ans2;
        }
        bool canReach(vector<int>& arr, int s) {
            vector<int> vis(arr.size(),0);
    
            return h(arr,s,vis);
        }
    };