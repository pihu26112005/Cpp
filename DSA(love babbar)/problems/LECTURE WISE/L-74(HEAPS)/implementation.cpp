#include<iostream>
using namespace std ;

class maxHeap
{
    public:
    int arr[100];
    int size ;

    maxHeap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int data)
    {
        size++;
        int child = size ;
        arr[child]=data;

        while (child>1) // correct place tk phunchao
        {
            int parent = child / 2 ;
            if (arr[parent]<arr[child])
            {
                swap(arr[parent],arr[child]);
                child = parent ;
            }
            else
            {
                return ;
            }
        }
    }
    
    void delet()
    {
        if (size==0)
            cout<<"nothing to dele"<<endl;
        
        int parent = 1 ;
        arr[parent]=arr[size];
        size--;
        while (parent<size)
        {
            int leftchild = 2*parent;
            int rightchild = 2*parent+1;
            if (arr[leftchild]>arr[parent] && leftchild<size)
            {
                swap(arr[parent],arr[leftchild]);
                parent = leftchild;
            }
            else if (arr[rightchild]>arr[parent] && rightchild<size)
            {
                swap(arr[parent],arr[rightchild]);
                parent = rightchild;
            }
            else
            {
                return ;
            }
        }
    }

    int minElement()
    {
        int minIndex = 1;
        for (int i = 1 ; i < size ; i++)
        {
            if (arr[i+1]<arr[i] && arr[i+1]<arr[minIndex])
            {
                minIndex = i+1;
            }
        }
        
        return arr[minIndex];
    }
};

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// building heap from array

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

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void heapSort(int arr[] , int n )
{
    int size = n ;
    while(size>1)
    {
        swap(arr[1],arr[size]);

        size--;

        heapify(arr,size,1);
    } 
    return ;
}