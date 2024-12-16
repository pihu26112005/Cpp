#include<iostream>
#include<vector>
using namespace std;

/****************************************************************************************************************************************************************************************/
// sare numbers ka multiply nikalo , then mul/arr[i] ans 
// but zero ka case handle nhi hoga , no zero , one zero , more the 1 zero 3 case handle krne pdenge 
vector<int> solve(vector<int> arr , int n)
{
    int mul=1;
    for (int i = 0; i < n; i++)
    {
        mul = mul*arr[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mul/arr[i]);
    }
    return ans ;
}

/****************************************************************************************************************************************************************************************/
// 2 array bnao 
// / ek me starting se elements ki multiply , ek me end se 
// for ith element ans = start[i-1]*end[i+1]