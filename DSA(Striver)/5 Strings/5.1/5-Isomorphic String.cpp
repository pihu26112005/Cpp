#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.length(); i++) {
            char cs = s[i];
            char ct = t[i];

            if (m1.count(cs)) {
                if (m1[cs] != ct) {
                    return false;
                }
            } else {
                m1[cs] = ct;
            }

            if (m2.count(ct)) {
                if (m2[ct] != cs) {
                    return false;
                }
            } else {
                m2[ct] = cs;
            }
        }
        return true;
    }
};
