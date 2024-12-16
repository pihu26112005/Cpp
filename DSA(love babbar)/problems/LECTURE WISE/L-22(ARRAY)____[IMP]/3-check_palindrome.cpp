// chcek if the string is palindrome 
  // ignore special characters , and lower/upper case 
  #include<iostream>
  using namespace std;
// phle sbhi lower me kr liye  , fir range lagage ke condition bna li

  string lower_case(string temp)
  {
    string temp2 ="";
    for (char i : temp)
    {
        if(i>='A' & i<='Z')
        {
          temp2.push_back(i-'A'+'a');
        }
        else
        {
          temp2.push_back(i);
        }
    }
    return temp2;
  }

  int find_length(string s)
  {
    int count =0;
    for (int i : s)
    {
      count ++;
    }
    return count;
  }

int main()
{
  string s ="A1b22B a";
  string s2 = lower_case(s);
  int start=0;
  int end = find_length(s)-1;
  while (start<=end)
  {
    // cout<<start<<"--< "<<s2[start]<<endl;
    // cout<<end<<"--< "<<s2[end]<<endl;
    if ((s2[start]<'a' | s2[start]>'z') & (s2[start]<'0' | s2[start]>'9')) 
    {
      start++;
      // cout<<"1st if"<<endl;
    }
    else if ((s2[end]<'a' | s2[end]>'z') & (s2[end]<'0' | s2[end]>'9')) 
    {
      end--;
      // cout<<"2nd if"<<endl;
    }
    else if (s2[start]!=s2[end])
    {
      cout<<"not a palindrome"<<endl;
      // cout<<"3rd if"<<endl;
      break;
    }
    else
    {
      start++;
      end--;
    }
    cout<<endl;
  }
  cout<<"yes palindrome"<<endl;
}