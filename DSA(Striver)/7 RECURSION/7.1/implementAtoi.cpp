#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void solve(string &s , string &ans , bool digitShuruHogae , bool digitKhatamHogae )
{
    if(s.length()==0)
        return ;

    char top = s.back();
    s.pop_back();
    if(top>='0' && top<='9' && digitShuruHogae && !digitKhatamHogae )
    {
        ans.push_back(top);
    }
    if((top<'0' || top>'9') && !digitKhatamHogae)
    {
        digitKhatamHogae = true;
    }

    solve(s,ans,digitShuruHogae,digitKhatamHogae);
}

int createAtoi(string s) 
{
    bool isPositive = true;
    reverse(s.begin(),s.end());
    if (s[s.size()-1] == '-') 
    {
        isPositive=false;
        s.pop_back();
    } 
    else if (s[s.size()-1] == '+')
    {
        s.pop_back();
    }

    string ans;
    solve(s,ans,true,false);
    int num = 0;
    for(int i=0;i<ans.length();i++)
    {
        int dig = ans[i]-'0';
        if (num > INT64_MAX / 10) 
        {
            // Overflow handling
            return (isPositive == 1) ? INT64_MAX : INT64_MIN;
        }
        num = num*10 + dig;
    }
    if(isPositive)
        return num;
    else
        return -1*num ;
}