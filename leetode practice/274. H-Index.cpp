class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans = 0;
        sort(c.begin(),c.end());
        for(int i=c.size()-1;i>=0;i--){
           int tp = c.size()-i;
           if(c[i]>=tp){
            ans = max(ans,tp);
           }
        }
        return ans;
    }
};