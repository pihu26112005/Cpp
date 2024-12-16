// same as set of pyhton 
// har element bs ek baar count hota hai 

#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(6);
    s.insert(1);
    s.insert(7);
    s.insert(7);
    
    
    cout<<s.count(7)<<endl; //just for chceking ki elesent hai ki nhi 
    cout<<s.count(0)<<endl;

    for(auto i : s)
    {
        cout<<i<<",";
    }
    cout<<endl;

    s.erase(7); // remove element 
    s.erase(0);

    for(auto i : s)
    {
        cout<<i<<",";
    }
    cout<<endl;

   auto it = s.find(3); // find the element and help us to print it and all jo iske sge hai 
   for(auto i=it; i!=s.end() ; i++)
   {
    cout<<*i<<" "<<","; 
   }
   cout<<endl;

}