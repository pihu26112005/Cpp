class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& q, int m) {
            vector<int> diff(nums.size() + 1, 0);
            for(int i = 0; i <= m; i++) { // creating diff array
                // diff[q[i][0]]++;
                // diff[q[i][1] + 1]--;
                 diff[q[i][0]]+= q[i][2];
                diff[q[i][1] + 1]-= q[i][2];
            }
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += diff[i]; // taking prefix sum up to i
                if(nums[i] > sum)
                    return false;
            }
            return true;
        }
    
        int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
            
            if(!isZeroArray(nums,q,q.size()-1)) return -1;
    
            bool isallzero = true;
            for(int i:nums) if(i!=0) isallzero=false;
            if(isallzero) return 0;
    
            int l=0;
            int e=q.size()-1;
            int ans=-1;
            while(l<=e){
                int m = l+(e-l)/2;
                if(isZeroArray(nums,q,m)){
                    ans = m;
                    e = m-1;
                }
                else l=m+1;
            }
            return ans+1;// ans is giving index 
        }
    };
    // Time complexity: O((n + q) * log q)
    // Space complexity: O(n)
    
    // Ist part q me sari queries ka use krke zero array banana tha 
    // IInd me order me start se leke min kitni query ka use krke zero array ban sakti hai vo batana hai 
    // IIIrd part me batana hai min kitni query ka use krke zero array bana sakte ho 