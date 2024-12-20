class Solution {
public:
    string reverseWords(string s) {
        // chatgpt bhai ne bas teen data preprocessing krd i - 
        // pahle koi space na ho. bich me double space na ho, end me soace na ho

        // Trim leading/trailing spaces and reduce multiple spaces to one
        string trimmed;
        int n = s.length();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        
        // Build trimmed version
        while (i < n) {
            if (s[i] != ' ') {
                trimmed += s[i];
            } else if (!trimmed.empty() && trimmed.back() != ' ') {
                trimmed += ' '; // Add a single space between words
            }
            i++;
        }
        
        // Remove trailing space
        if (!trimmed.empty() && trimmed.back() == ' ') {
            trimmed.pop_back();
        }

        // my approach start here --

        // Reverse the entire string
        reverse(trimmed.begin(), trimmed.end());

        // Reverse each word
        int start = 0;
        for (int end = 0; end <= trimmed.size(); end++) {
            if (end == trimmed.size() || trimmed[end] == ' ') {
                reverse(trimmed.begin() + start, trimmed.begin() + end);
                start = end + 1;
            }
        }
        
        return trimmed;
    }
};
