// pura same code likha maine but isme print  hi nhi kr rha hai

#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int count_small=0;
    int size = e-s+1;
    for (int i = s; i < size; i++)
    {
        if (arr[i]<arr[s])
        {
            count_small++;
        }
    }
    int index = s+count_small;
    swap(arr[s],arr[index]);
    int i=s,j=e;
    while (i<index && j>index)
    {
        while (arr[i]<=arr[index])
        {
            i++;
        }
        while (arr[j]>arr[index])
        {
            j--;
        }
        if (i<index && j>index)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return count_small;
}

void quick_sort(int arr[], int s, int e)
{
    if (s>=e) // base case
    {
        return ;
    }

    int p = partition (arr, s, e);
    
    quick_sort(arr, s, p-1); // left part
    quick_sort(arr, p+1, e); // right part
}

int main()
{
    int arr[5]={3,5,2,9,1};
    quick_sort(arr, 0, 4);

    cout<<"2";
    for (int i = 0; i < 5; i++)  
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}