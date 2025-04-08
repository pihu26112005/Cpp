class Solution {
    public:
        void keypad_solve(string string_digit, int index, vector<string>& ans,
                          string output, string mapping[]) {
    
            // base case
            if (index >= string_digit.length()) {
                if(output!="")
                    ans.push_back(output);
                return;
            }
    
            int numerical_value = string_digit[index] - '0'; // typecast
            string mapped_value =
                mapping[numerical_value]; // mapping jaise 2--> "abc"
    
    
            for (int i = 0; i < mapped_value.length(); i++) {
                // include 
                output.push_back(mapped_value[i]);
                keypad_solve(string_digit, index + 1, ans, output, mapping);
                output.pop_back();
            }
        }
        vector<string> letterCombinations(string s) {
            vector<string> ans;
            string output;
            int index = 0;
            string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
            keypad_solve(s, index, ans, output, mapping);
            return ans;
        }
    };