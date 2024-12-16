// PRINCIPLE - first in last out

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> st; 
    st.push(1); // pushing elements 
    st.push(2);
    st.push(3);
    st.push(0);
    st.push(-1);
    st.pop(); //first in first out element removed 
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    // st.empty();


//  st.pop_back(); NHI HOTA 
//  st.pop_front(); NHI HOTA 
// cout<<l.capacity()<<endl;  NHI HOTA 
// cout<<st.front()<<endl;
// cout<<st.back()<<endl;

}