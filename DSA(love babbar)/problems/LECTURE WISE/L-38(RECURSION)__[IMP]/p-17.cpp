// KEYPAD PROBLEM
// letter combination of a phone number 
// program shi hai but output kyo nhi de rha 

#include<iostream>
#include<vector>
using namespace std;

void keypad_solve(string string_digit, int index, vector<string>& ans, string output , string mapping[])
{

    int numerical_value = string_digit[index]-'0'; // typecast
    string mapped_value = mapping[numerical_value]; // mapping jaise 2--> "abc"

    //base case 
    if (index > string_digit.length())
    {
        ans.push_back(output);
        return ;
    }

    for (int i = 0; i < mapped_value.length(); i++)
    {
        output.push_back(mapped_value[i]);
        keypad_solve(string_digit, index+1, ans, output, mapping);
        output.pop_back();
    }

}

int main()
{
    // string s;
    // cin>>s;
    string s = "23";
    vector<string> ans;
    string output;
    int index =0;
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypad_solve(s, index, ans, output, mapping);
}