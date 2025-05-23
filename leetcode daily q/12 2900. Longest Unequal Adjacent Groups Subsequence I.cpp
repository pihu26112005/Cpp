class Solution {
    public:
        vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
            if(g.size()==0) return w;
    
            vector<string> ans;
            bool f= g[0]==1 ? true : false ;
            for(int i=0;i<g.size();i++){
                if(f){
                    if(g[i]==1){
                        ans.push_back(w[i]);
                        f=false;
                    }
                }
                else{
                    if(g[i]==0){
                        ans.push_back(w[i]);
                        f=true;
                    }
                }
            }
            return ans;
        }
    };