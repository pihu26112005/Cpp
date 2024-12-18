class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(j<=s.length())
        {
            if(s[j]==' ' || j==s.length())
            {
                int st=i;
                int e=j-1;
                while(st<e)
                {
                    char t=s[st];
                    s[st]=s[e];
                    s[e]=t;
                    st++;
                    e--;
                }
                while(j<s.length() && s[j]==' ')
                    {
                        j++;
                    }
                i=j;
                // j++;
            }
            else
                j++;
        }


        i=0;
        j=s.length()-1;
        while(i<j)
        {
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
        return s;
    }
};