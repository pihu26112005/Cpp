// subsequence of string 
// using recursion , subsequence of string 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// exclude - include principle 
                                                                                                          
void subset_calc(string arr, int index, string temp_output, vector<string>& ans)
{
    if (index>=arr.size()) // base case 
    {
        ans.push_back(temp_output);
        return ;
    }
    
    // exclusion 
    subset_calc(arr, index+1, temp_output, ans);

    // inclusion 
    char element = arr[index];
    temp_output.push_back(element);
    subset_calc(arr, index+1, temp_output, ans);
}

int main()
{
    string arr ="abc";
    vector<string> ans;
    string temp_output;
    int index = 0;

    subset_calc(arr, index, temp_output, ans);


}