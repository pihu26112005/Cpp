// allocate books 
// given an array ( need not to be sorted )
// chal shi rha hai but time limit exceed kr rha hai 
// video 1st soln
#include<iostream>
using namespace std;

bool issolution(int arr[], int sum, int book, int student, int m)
{
    int i =0;
    int comp=0;
    int total_pages = 0;
    int j =  -1;
    
    while (total_pages < sum)
    {
       while (comp<=m)
       {
            j++;
            comp = comp + arr[j];
       }
       total_pages = total_pages + comp;
       total_pages = total_pages - arr[j];
       comp = 0 ;
       j--;
       i++;
    }
    if (i<=student)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int bookallocate (int arr[],int books,int student)
{
    int s=0;
    int sum=0;
    int ans = 0;
    for (int i = 0; i < books; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int m=(e+s)/2;

    while (s<e)
    {
        if (student > books)
        {
            return -1;
        }
        
        if (issolution( arr, sum, books, student, m ))
        {
            ans = m;
            e=m-1;
        }
        else
        {
            s=m+1;
        }
        m=s+(e-s)/2;
    }
    return ans ;
}

int main()
{
    int arr[4]={12,34,67,90};
    int a=bookallocate(arr,4,2);
    cout<<"a"<<a<<endl;
}