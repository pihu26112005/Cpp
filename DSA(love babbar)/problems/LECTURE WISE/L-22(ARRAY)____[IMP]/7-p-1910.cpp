// remove all occurence of string 
// video solution
#include<iostream>
using namespace std;
int main()
{
    string s="dabcabcdgghabc";
    string part = "abc";
    while (s.length()>0 & s.find(part)<s.length() ) 
    {
        s.erase(s.find(part),part.length());
    }
    cout<<s<<endl;
}

// QUERY - why s.find(part)<s.length()  used 
  // jab tak part pattern present hoga s me tb tk s.find kuch index dega toh s.length se comparable hoga 
    // but jb part nhi bachega s me , tb s.find " std::string::npos" dega , jo comparable nhi hai s.lemgth se , so condition false ho jayegi 