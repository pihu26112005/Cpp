class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;  // Pointer for children
        int cookie = 0; // Pointer for cookies
        int ans = 0;    // Number of satisfied children

        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) { // If the cookie can satisfy the child
                ans++;
                child++;
            }
            cookie++; // Always move to the next cookie
        }
        return ans;
    }
};


// tc - o(nlogn+klogk)
// sc - o(n+k)