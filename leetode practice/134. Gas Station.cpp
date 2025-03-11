
// my solutuion 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> arr;
        int s = 0;  
        int fn = 0; // Start from index 0
        
        for (int i = 0; i < gas.size(); i++) {
            arr.push_back(gas[i] - cost[i]);
            s += arr[i];
        }

        if (s < 0) return -1; // No solution exists

        int ans = 0, cs = 0; // `cs` is current sum of gas left
        
        for (int i = 0; i < gas.size(); i++) {
            cs += arr[i];
            if (cs < 0) {
                ans = i + 1; // Start from next station
                cs = 0;  // Reset tank
            }
        }
        return ans;
    }
};


