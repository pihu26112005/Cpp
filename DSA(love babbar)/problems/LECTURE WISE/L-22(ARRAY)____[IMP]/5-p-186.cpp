// reverse each word 

#include <iostream>
using namespace std;

int main() {
    string s = "My name is Piyush"; // ans -->  yM eman si hsuyiP
    string s2 = "";
    int start = 0;
    int end = 0;
    int i = 0;
    
    while (i < s.length()) {
        start = i;
        while (s[i] != ' ' && i < s.length()) {
            i++;
        }
        end = i - 1;
        
        for (int j = end; j >= start; j--) {
            s2.push_back(s[j]);
        }
        
        if (i != s.length()) {
            s2.push_back(s[i]);
        }
        
        i++;
    }
    cout << s2 << endl;
    return 0;
}

