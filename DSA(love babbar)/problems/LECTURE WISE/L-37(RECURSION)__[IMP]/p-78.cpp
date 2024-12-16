// powerset of a set 
// using recursion , calculation of all possibble subset of a set , or 

#include<iostream>
#include<vector>
using namespace std;

// exclude - include principle 
                                                                                                          
void subset_calc(vector<int> arr, int index, vector<int> temp_output, vector<vector<int>>& ans)
{
    if (index>=arr.size()) // base case 
    {
        ans.push_back(temp_output);
        return ;
    }
    
    // exclusion 
    subset_calc(arr, index+1, temp_output, ans);

    // inclusion 
    int element = arr[index];
    temp_output.push_back(element);
    subset_calc(arr, index+1, temp_output, ans);
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int>> ans;
    vector<int> temp_output;
    int index = 0;

    subset_calc(arr, index, temp_output, ans);



    for(vector<int> i : ans)
    {
        cout<<"[ ";
        for(int j : i)
        {
            cout<<j<<" ";
        }
        cout<<" ]";
        cout<<endl;
    }
}