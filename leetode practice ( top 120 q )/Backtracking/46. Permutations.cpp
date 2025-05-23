class Solution {
    public:
        void permutation_calculation(vector<vector<int>>& ans, vector<int> arr, int index) {
            if (index >= arr.size()) // base case
            {
                ans.push_back(arr);
                return;
            }
    
            for (int i = index; i < arr.size(); i++) {
                swap(arr[index], arr[i]);
                permutation_calculation(ans, arr, index + 1);
                swap(arr[index], arr[i]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            permutation_calculation(ans,nums,0);
            return ans;
        }
    };


    // TC and SC - O(n × n!)