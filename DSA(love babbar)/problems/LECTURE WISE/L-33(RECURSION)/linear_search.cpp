// using recusrsion linear search

#include<iostream>
using namespace std;
bool linear_search(int arr[] ,int n, int key)
{
    if (n==0)
    {
        return false ;
    }
    if (key == arr[0])
    {
        return true;
    }
    
    else
    {
        return linear_search(arr+1, n-1, key);
    }
}

int main()
{
    int arr[5]={1,2,3,4,6};
    int key;
    cin>>key;
    cout<<linear_search(arr, 5,key)<<endl;
    
}