#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(9);
    cout<<binary_search(arr.begin(),arr.end(),8)<<endl;;
    cout<<binary_search(arr.begin(),arr.end(),6)<<endl;;

    sort(arr.begin(), arr.end(),greater<int>()); //descending sort 
    sort(arr.begin(), arr.end()); // ascending sort 

    for (auto num : arr) 
    {
    cout << num << " ";
    }
    cout<<endl;

    int a=2;
    int b=5;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;

// upper , lower bound bhi hai but likha nhi 
}