// First and Last Position of an Element In Sorted Array
// sorted arrayy 
#include<iostream>
using namespace std;

int indexfirst(int arr[] , int n , int key)
{
  int start = 0 , end = n-1;
  int ans = -1 ;
  int mid = start + ((end - start)/2);
  while (start <= end )
  {
    if (key > arr[mid])
    {
        start = mid + 1;
    }
    else if (key < arr[mid])
    {
        end = mid - 1 ;
    }
    else 
    {
        ans = mid;
        end = mid-1;
    }
    mid = start + ((end - start)/2);

  }
  return ans ;
}

int indexlast(int arr[] , int n , int key)
{
  int start = 0 , end = n-1;
  int ans = 0 ;
  int mid = start + ((end - start)/2);
  while (start <= end )
  {
    if (key > arr[mid])
    {
        start = mid + 1;
    }
    else if (key < arr[mid])
    {
        end = mid - 1 ;
    }
    else 
    {
        ans = mid;
       start = mid+1;
    }
     mid = start + (end-start)/2;
  }
  return ans ;
}
int main()
{
  int key;
  cin>>key;
  int arr[10]={1,2,3,3,4,5,5,5,6,7};
  pair<int,int>p;
  p.first = indexfirst(arr,10,key);
  p.second = indexlast(arr,10,key);
  cout << "First index: " << p.first << endl;
  cout << "Last index: " << p.second << endl;
}