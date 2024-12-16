// like dictionary 
//key --> first , value --> second

#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,string> m;
    m[1]="pihu";
    m[3]="piyu";
    m.insert({7,"piyush"});
    
    cout<<m.count(7)<<endl; //just for chceking ki element hai ki nhi 
    cout<<m.count(0)<<endl;

    for(auto i : m)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }

    m.erase(7); // remove element 
    m.erase(0);

    for(auto i : m)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }

   auto it = m.find(3); // find the element and help us to print it and all jo iske sge hai 
   for(auto i=it; i!=m.end() ; i++)
   {
    cout<<(*i).first<<":"<<(*i).second<<endl; 
   }

}