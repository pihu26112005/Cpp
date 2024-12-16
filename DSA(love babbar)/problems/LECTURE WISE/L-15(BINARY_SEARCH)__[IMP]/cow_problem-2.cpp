
// better than 99.9% 

#include<iostream>
#include<algorithm>
using namespace std;

bool issolution(int arr[], int n, int k, int mid)
{
    int cow_count = 1;
    int last_position = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i]-last_position)>=mid)
            {
                cow_count++;
                if (cow_count == k)
                {
                    return true;
                }
                last_position = arr[i];
            }
        }
    return false;
}

int cowallocate(int arr[], int n, int k)
{
    // need of sorting code first here 
    int s=0;
    int mymax = -1;
    for (int i = 0; i < n; i++)
    {
        mymax=max(mymax,arr[i]);
    }
    int e = mymax;
    int ans = -1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        cout<<"mid"<<mid<<endl;
        if(k>n)
        {
            return ans;
        }
        if (issolution( arr,n,k,mid ))
        {
            ans = mid;
            cout<<"ans"<<ans<<endl;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans ;
}


int main()
{
    int arr[10]={18,27,44,77,69,19,35,83,9,64 };
    int a=cowallocate(arr,10,4);
    cout<<a<<endl;
}