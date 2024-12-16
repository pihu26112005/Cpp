// allocate books 
// given an array ( need not to be sorted )
// video 2nd soln

#include<iostream>
using namespace std;

bool issolution(int arr[], int book, int student, int m)
{
    int pages = 0;
    int student_count =1;
    for (int i = 0; i < book; i++)
    {
        if (pages + arr[i] <= m)
        {
            pages = pages + arr[i];
        }
        else
        {
            student_count++;
            if ((student_count > student) || (arr[i] > m))
            {
                return false;
            }
            pages = arr[i];
        }
        if(student_count > student)
        {
            return false;
        }
    }
    return true;
}

int bookallocate(int arr[], int n, int m) {
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        if(m>n)
        {
            return ans;
        }
        if (issolution( arr,n,m, mid ))
        {
            ans = mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans ;
}


int main()
{
    int arr[5]={10,20,40,30,10};
    int a=bookallocate(arr,5,2);
    cout<<"a"<<a<<endl;
}