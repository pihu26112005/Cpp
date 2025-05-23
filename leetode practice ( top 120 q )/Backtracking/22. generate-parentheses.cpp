class Solution {
    public:
        void h(string s, vector<string> &ans, int idx, unordered_map<string,bool> &m ){
            if(idx >= s.length()){
                if(m[s]==false){
                    ans.push_back(s);
                    m[s]=true;
                }
                return;
            }
    
            for(int i=idx;i<s.length();i++){
                if(i==idx || (s[idx]==')' && s[i]=='(')){
                    swap(s[idx],s[i]);
                    h(s,ans,idx+2,m);
                    swap(s[idx],s[i]);
                }
            }
        }
    
        vector<string> generateParenthesis(int n) {
            unordered_map<string,bool> m;
            vector<string> ans;
            string s = "";
            for(int i=0;i<n;i++){
                s+="()";
            }
            h(s,ans,1,m);
            reverse(ans.begin(), ans.end()); // Reverse here
            return ans;
        }
    };
    
    // using conceot of permutations - replacment principle 
    // eg - ()() , isse hum (()) ye bana skte hai by replaceing two bracekt ) with (