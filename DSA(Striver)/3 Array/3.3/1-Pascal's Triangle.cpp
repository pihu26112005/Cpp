class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> x;
        x.push_back({1});
        if(n == 1) return x;
        
        x.push_back({1, 1});
        if(n == 2) return x;
        
        for(int i = 2; i < n; i++) {
            vector<int> temp;
            temp.push_back(1);  // First element is always 1

            // Use `x.back()` to get the last row
            vector<int>& t2 = x.back();
            for(int j = 0; j < t2.size() - 1; j++) {
                int tt = t2[j] + t2[j + 1];
                temp.push_back(tt);
            }
            temp.push_back(1);  // Last element is always 1
            x.push_back(temp);
        }
        
        return x;
    }
};
