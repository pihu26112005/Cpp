class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int ans = 0;
        int s = 0; 
        unordered_map<int, int> m; 

        for (int e = 0; e < arr.size(); e++) {
            m[arr[e]]++;  
            
            while (m.size() > 2) {  
                m[arr[s]]--;  
                if (m[arr[s]] == 0) {
                    m.erase(arr[s]); 
                }
                s++;  
            }
            
            ans = max(ans, e - s + 1); 
        }
        
        return ans;
    }
};
