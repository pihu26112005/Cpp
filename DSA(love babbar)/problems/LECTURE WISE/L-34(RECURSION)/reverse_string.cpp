// using recusrsion , reverse a string (2) : 

#include<iostream>
using namespace std;
void reverse_string(string& x, int i, int j )
{
    if (i>j)
    {
        return ;
    }
    swap(x[i],x[j]);
    i++;
    j--;
    reverse_string(x, i, j);
}

int main()
{
    string s ="abcde";
    reverse_string(s, 0, s.length()-1);   
    cout<<s;

}

//solve it using only i 