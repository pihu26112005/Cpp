// using recusrsion , reverse a char array : 

#include<iostream>
using namespace std;
void reverse_string(char x[] )
{
    if (x[0]=='\0')
    {
        return ;
    }
    reverse_string(x+1);
    cout<<x[0];

    // cout<<reverse_string(x+1)<<x[0]; --> wrong hai kyooki reverse_string khud cout kar rha hai toh kya tum cout kt andar cout kroge
}

int main()
{
    // string s ="abcde";
    // cout<<reverse_string(s);   

    char s[6] ="abcde";
    reverse_string(s);  
}