class Solution {
public:
    int maxDepth(string s) {
        if(s.length()==1)
        {
            return 0;
        }
        int ans = 0;
        int m = 0;
        for(char c:s)
        {
            if(c=='(')
            {
                ans++;
                m=max(m,ans);
            }
            else if(c==')')
            {
                ans--;
                m=max(m,ans);
            }
        }
        return m;
    }
};