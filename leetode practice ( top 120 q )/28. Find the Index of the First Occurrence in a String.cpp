class Solution {
public:
    int strStr(string h, string s) {
        for(int i=0;i<h.length();i++){
            if(h[i]==s[0]){
                int j=0;
                while(j<s.length() && j+i<h.length() && h[j+i]==s[j]) j++;
                if(j==s.length()) return i;
            }
        }
        return -1;
    }
};