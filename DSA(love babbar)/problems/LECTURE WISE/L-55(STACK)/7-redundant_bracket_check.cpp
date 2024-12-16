// expression me extra bracket na ho   eg (a+(b*(a/c)))) isme ek rebundant bracket hai , ((a+b)) isme do
// TC - o(n)

#include <iostream>
#include <stack>
using namespace std;

bool chcek_redundant(string &s)
{
    stack<char> temp;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if ((s[i] == '(') || (s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
        {
            temp.push(s[i]);
        }
        else if (s[i] == ')')
        {
            bool firstiter = false;
            while (temp.top() != '(')
            {
                if ((temp.top() == '+') || (temp.top() == '-') || (temp.top() == '*') || (temp.top() == '/'))
                {
                    temp.pop();
                    firstiter = true;
                }
            }
            temp.pop();
            if (firstiter == false)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s = "(a+(b*(a/c)))";
    if (chcek_redundant(s))
    {
        cout << " yes";
    }
    else
    {
        cout << " no";
    }
}