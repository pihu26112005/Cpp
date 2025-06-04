class Solution {
    public:
        string answerString(string w, int nf) {
            int n=w.length();
            if(nf==1) return w;
            if(nf>n)
                return "";
    
            int mxl=n-nf+1;
            char mxc='a';
            for(char c:w){
                mxc=max(mxc,c);
            }
            // cout<<mxl<<" "<<mxc;
            string ans="";
            for(int i=0;i<n;i++){
                if(w[i]==mxc){
                    int l=min(mxl,n-i);
                    string t=w.substr(i,l);
                    ans=max(ans,t);
                }
            }
            return ans;
        }
    };
    
    // i think ki haar baar ans string us char se hi start hogi jo sabse bada char ho alphabatecally 
    // but "gh" 1 --> isme aisa nhi hua 