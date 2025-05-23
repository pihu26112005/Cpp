class Solution {
    public:
        string pushDominoes(string d) {
            int n = d.length();
            string ans = "";
            int f = 0, l = n - 1;
    
            while (f < n && d[f] == '.') f++;
            if(f==n) return d;
            while (l >= 0 && d[l] == '.') l--;
    
            if (f < n && d[f] == 'L') {
                ans += string(f, 'L');
            } else {
                ans += string(f, '.');
            }
    
            int i = f;
            ans+=d[i];
            while (i <= l) {
                int j = i + 1;
                while (j <= l && d[j] == '.') j++;
    
                // ans += d[i];
    
                if (j > l) {
                    if (d[i] == 'R') {
                        ans += string(n - i - 1, 'R');
                    } else {
                        ans += string(n - i - 1, '.');
                    }
                    break;
                }
    
                if (d[i] == 'L' && d[j] == 'L') {
                    ans += string(j - i - 1, 'L');
                } else if (d[i] == 'R' && d[j] == 'R') {
                    ans += string(j - i - 1, 'R');
                } else if (d[i] == 'L' && d[j] == 'R') {
                    ans += string(j - i - 1, '.');
                } else {  // d[i] == 'R' && d[j] == 'L'
                    int gap = j - i - 1;
                    int left = gap / 2;
                    int right = gap / 2;
                    int mid = (gap%2==0) ? 0 : 1;
                    ans += string(left, 'R') + string(mid,'.') + string(right, 'L');
                }
    
                ans += d[j];
                i = j;
            }
    
            return ans;
        }
    };
    