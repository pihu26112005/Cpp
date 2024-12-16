
#include<iostream>
using namespace std ;
void heapify(int arr[] , int n , int i) // TC = o(log(n))
{
    int parent = i ; // index jisko shi jagah puchana hai
    int leftchild = 2*parent;
    int rightchild = 2*parent+1;

    if (leftchild<=n && arr[leftchild]>arr[parent])
    {
        parent = leftchild;
    }
    if (rightchild<=n && arr[rightchild]>arr[parent])
    {
        parent = rightchild;
    }

   if (parent!=i)
   {
     swap(arr[parent],arr[i]);
     heapify(arr,n,parent);
   }
   return ;
}

void build_heap(int arr[] , int n)
{
    for (int i = n/2; i >0; i--)
    {
        heapify(arr,n,i);
    }
    return ;
}

void mergeHeaps(int arr1[] , int arr2[] , int n , int m)
{
    int size = n+m;
    int arr3[size];
    for (int i = 0; i < n; i++)
    {
        arr3[i]=arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr3[i+n]=arr2[i];
    }

    for (int i = size/2; i >0; i--)
    {
        heapify(arr3,size,i);
    }
}