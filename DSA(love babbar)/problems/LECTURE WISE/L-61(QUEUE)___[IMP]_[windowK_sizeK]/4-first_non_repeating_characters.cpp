// code studio vala 

// NOT WORKING 
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
bool phle_kbhi_aaya(deque<char> q , char k)
{
    while(q.size()!=0)
    {
        if(q.front()==k)
        {
            return true;
        }
        q.pop_front();
    }
    return false ;
}

char agla_unique_element (deque<char>& q , char& k)
{
    char khali = ' ' ;
    bool kya_element_hai = false;
    deque<char> q2 (q.begin() , q.end());
    while(q2.size()>0)
    {
        if(k == q2.front())
        {
            kya_element_hai = true;
            break;
        }
        q2.pop_front();
    }

    if(kya_element_hai)
    {
        while(k!=q.front())
        {
            q.pop_front();
        }
        q.pop_front();
        if(q.size()>0)
        {
            return q.front();
        }
        else
        {
            return khali ;
        }
    }
    else
    {
        return khali ;
    }
}

vector<char> firstNonRepeating(string s) 
{
    vector<char> ans; // answer
    deque<char> q; // queue of unique elements
    char temp ; // current unique element
    bool firstiter = true ;

    ans.push_back(s[0]);
    q.push_back(s[0]);
    temp = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]!=s[i-1])
        {
           if (phle_kbhi_aaya(q,s[i])) // new unique nhi hai  
           {
                temp = agla_unique_element(q,s[i]);
                if(temp!=' ')
                {
                    ans.push_back(temp);
                }
           }
           else // new unique hai 
           {
                q.push_back(s[i]);
                if(temp == ' ')
                {
                    temp = s[i];
                    ans.push_back(temp);
                }
                else
                {
                    ans.push_back(temp);
                }
           }
        }
        else
        {
            if(q.size()>0)
            {
                q.pop_back();
                if(temp == s[i])
                {
                    temp = ' ';
                }
                else
                {
                    if(q.size()>0)
                    {
                        temp = q.back();
                    }
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s = "bbabcbcab";
    vector<char> ans = firstNonRepeating(s);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}