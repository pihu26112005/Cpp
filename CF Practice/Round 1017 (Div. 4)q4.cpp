#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string p, s;
        cin >> p;
        cin >> s;

        bool ans = true;
        int i = 0, j = 0;
        while (i < p.length() && j < s.length())
        {
            char ch = p[i];
            int pc = 0;
            while (i < p.length() && p[i] == ch)
            {
                pc++;
                i++;
            }
            int sc = 0;
            while (j < s.length() && s[j] == ch)
            {
                sc++;
                j++;
            }
            if (sc < pc || sc > 2 * pc)
            {
                ans = false;
                break;
            }
        }
        if (i != p.length() || j != s.length())
            ans = false;

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}