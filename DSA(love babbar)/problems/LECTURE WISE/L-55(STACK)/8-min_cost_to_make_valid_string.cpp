#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s = "{}{}}{}{{}";
    stack<char> temp;
    stack<char> temp2;
    int count= 0;
    int count2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='{')
        {
            temp.push(s[i]);
            count++;
        }
        else 
        {
            if (!temp.empty())
            {
                temp.pop();
                count--;
            }
            else
            {
                temp2.push(s[i]);
                count2++;
            }
        }
    }
    if((count%2!=0 && count2%2==0) || (count2%2!=0 && count%2==0))
    {
        cout<<-1;
    }
    else if (count2 == 0)
    {
        if (count%2==0)
        {
            cout<<count/2;
        }
        else
        {
            cout<<-1;
        }
    }
    else if(count==0)
    {
        if (count2%2==0)
        {
            cout<<count2/2;
        }
        else
        {
            cout<<-1;
        }
    }
    else
    {
        if (count%2==0 && count2%2==0)
        {
            cout<<(count+count2)/2;
        }
        else
        {
            cout<<(count+count2)/2 +1;
        }
        
    }

}