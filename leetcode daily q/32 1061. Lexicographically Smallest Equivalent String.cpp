class Solution {
    public:
        void makeset(vector<int>& p, vector<int>& r) {
            for (int i = 0; i < p.size(); i++) {
                p[i] = i;
                r[i] = 0;
            }
        }
    
        int findp(vector<int>& p, int i) {
            if (p[i] == i)
                return i;
            else
                return p[i] = findp(p,p[i]);
        }
    
        void unn(int u, int v, vector<int>& p, vector<int>& r) {
            int uu = findp(p,u);
            int uv = findp(p,v);
    
            // if (r[uu] < r[uv]) {
            //     p[uu] = uv;
            // } else if (r[uv] < r[uu]) {
            //     p[uv] = uu;
            // } else {
                if (uu < uv) {
                    p[uv] = uu;
                    // r[uu]++;
                } else {
                    p[uu] = uv;
                    // r[uv]++;
                }
            // }
        }
        string smallestEquivalentString(string s1, string s2, string b) {
            vector<int> p(26, 0);
            vector<int> r(26, 0);
    
            makeset(p,r);
    
            int n = s1.length();
            for (int i = 0; i < n; i++) {
                char c1 = s1[i];
                char c2 = s2[i];
                int u = c1 - 'a';
                int v = c2 - 'a';
                if (findp(p,u) != findp(p,v)) {
                    unn(u, v, p, r);
                }
            }
    
            string ans = "";
            for (char c : b) {
                int t = c - 'a';
                // int x = p[t];
                int x = findp(p,t);
                ans += ('a' + x);
            }
    
            return ans;
        }
    };
    
    // rank is of no use 
    // and finally parent array me nhi dekhna , har component ka final parent nikalne ke liye findp ka use kre 