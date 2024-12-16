// print that character jo string me max bar occur hua ho
  // treat upper and lower case same 
  // special character nhi hai , space nhi hai 

#include<iostream>
using namespace std;
int main()
{
// ek array bnae hai jisme 26 '0 hai , hum hr alphabet ko numbers se represent rk rhe hai a,A-0 , b,B-1 ...
  // jitni bar koi alphabet hai , uske number ke corresponding index ki value bda rhe hai
    // fir max value is array se nikal kar , iska index ke corresponding alphabet print kr rhe hai 
    string s="anemotpoa";
    int arr[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int num = 0;
        if (ch>='a' & ch<='z') // lower case 
        {
            num = ch-'a';
            arr[num]++;
        }
        else   // lower case 
        {
            num = ch-'A';
            arr[num]++;
        }
    }
    int max_count = 0;
    for (int i = 0; i < 26; i++)
    {
        max_count = max(max_count,arr[i]);
    }
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i]==max_count)
        {
            index=i;
        }
    }
    char final = 'a'+index;
    cout<<final<<endl;
}