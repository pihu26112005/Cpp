class Solution {
public:
    bool rotateString(string s, string t) {
        int n = s.length();
        if (n != t.length())
            return false;
        
        return (s + s).find(t) != string::npos;
        // index return krega and check krega agar nhi hogi toh index npos ayega 
        
    }
};
