// remove all adjacent duplicates 
  // not optimized soln , video me bhi nhi hai kyooki hw tha 
#include<iostream>
using namespace std;
int main()
{
  string s = "abbaca";
  string temp ="";
  int i=0;
  while (i+1<s.length())
  {
    if (s[i]==s[i+1])
    {
        s.erase(i,2);
        i=0;
    }
    else
    {
        i++;
    }
  }
  cout<<s<<endl;
}