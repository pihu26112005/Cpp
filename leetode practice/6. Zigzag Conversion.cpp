class Solution {
public:
    string convert(string s, int n) {
        if(s.length()==1 || s.length()==2)
            return s;
        if(n==1)
            return s;
        string ans;
        for(int i=0;i<n;i++){
            int j=i;
            bool iter = true;
            while(j<s.length()){
                ans+=s[j];
                if(i==0 || i==n-1)
                    j+=(n-1 + n-2 +1);
                else{
                    if(iter){
                        j+=(n-(i+1) + n-(i+1));
                        iter = false;
                    }
                    else{
                        j+=(i + i);
                        iter = true;
                    }
                }
            }
        }
        return ans;
    }
};