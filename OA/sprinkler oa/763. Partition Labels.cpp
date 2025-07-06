class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n=s.length();
            unordered_map<char,int> m;
            for(int i=0;i<n;i++) m[s[i]]=i;
    
            vector<int> ans;
            int i=0;
            while(i<n){
                int st=i;
                int e=i;
                while(st<=e){
                    e=max(e,m[s[st]]);
                    st++;
                }
                int len = e-i+1;
                if(len!=0) ans.push_back(len);
                i=st;
            }
            
            return ans;
        }
    };