// merge sort --> basically using binary search vala method to sort in sorting :

#include<iostream>
using namespace std;

void merge(int* arr1,int p, int* arr2, int q, int* arr, int n)
{
    int a=0, b=0, c=0;
    while (a<p && b<q)
    {
        if (arr1[a]>arr2[b])
        {
            arr[c]=arr2[b];
            c++;
            b++;
        }
        else
        {
            arr[c]=arr1[a];
            c++;
            a++;
        }
    }
    while (a<p)
    {
        arr[c]=arr1[a];
        c++;
        a++;
    }
    while (b<q)
    {
        arr[c]=arr2[b];
        c++;
        b++;
    }

}

void merge_sort(int* arr , int s, int e)
{
    int n = e-s+1;// size of arr

    if (s>=e) // base case 
    {
        return ;
    }

    int mid = s+(e-s)/2;

    // breaking array int two peices 
    int len1 = mid - s+1, len2 = e-mid;
    int a1[len1];
    int a2[len2];

    for (int i = 0; i < mid-s+1; i++)
    {
        a1[i]=arr[i];
    }
    for (int i = 0; i < e-mid; i++)
    {
        a2[i]=arr[i+mid+1];
    }

    // recursively using merge_sort in left and right side : 
    merge_sort(a1,0,mid-s);
    merge_sort(a2,0,e-mid-1);

    // mergeing left and right part into parent array 
    merge(a1, len1, a2, len2, arr, n);

}

int main()
{
    int arr[5]={1,6,4,8,2};
    merge_sort(arr, 0, 4);
 
    for (int i = 0; i < 5; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    
}