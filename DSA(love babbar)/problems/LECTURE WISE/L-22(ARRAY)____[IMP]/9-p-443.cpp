// string compression 

#include<iostream>
using namespace std;
int main()
{
    char chars[7] = {'a','a','b','b','c','c','c'};
    int n=7;
    int i=0;
    int count=0;
    int index=0;
    while (i<n)
    {
        int j=i+1;
        while (j<n & chars[i]==chars[j])
        {
            j++;
        }
        chars[index++]=chars[i];
        count = j-i;
        if (count>1)
        {
            string s=to_string(count);
            for(char ch : s)
            {
                chars[index++]=ch;
            }
        }
        i=j;
    }
    cout<<chars<<endl;
}