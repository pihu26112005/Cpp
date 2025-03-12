class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while(i>=0 && s[i]==' ') i--;
        int e=i;
        while(i>=0 && s[i]!=' ') i--;
        int st=i;
        return e-st;
    }
};