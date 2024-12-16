// pichle jaisa hi hai 
// bus space bhi ignore krna hai 
#include<iostream>
using namespace std;

int find_length(string s)
{
  int count =0;
  for (int i : s)
  {
    count ++;
  }
  return count;
}

 string final_string(string temp)
{
    int i=0;
    string temp2 ="";
    while(i<find_length(temp))
    {
        if(((temp[i]<'A' | temp[i]>'Z') & (temp[i]<'a' | temp[i]>'z') & (temp[i]<'0' | temp[i]>'9')) | (temp[i]==' '))
        {
            i++;
        }
        else if (temp[i]>='A' &  temp[i]<='Z')
        {
            temp2.push_back(temp[i]-'A'+'a');
            i++;
        }
        else
        {
            temp2.push_back(temp[i]);
            i++;
        }
    }
    return temp2;
}

int main()
{
    string s ="race a car";
    string x=final_string(s);
    int start=0;
    int end = find_length(x)-1;
    while (start<=end)
    {
        if (x[start]!=x[end])
        {
            cout<<"false"<<endl;
            break;
        }
        else
        {
            start++;
            end--;
        }
    }
    cout<<"true"<<endl;
}