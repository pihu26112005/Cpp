// aggeressive cow problem 
// fully working bs sorting mechanism ka ek kjagah use krna hai 
// submission me sorting ka use kr diya hai 
// better than 30 % 

#include<iostream>
#include<algorithm>
using namespace std;

bool issolution(int arr[], int n, int k, int mid)
{
    int cow_count = 1;
    int j=0;
    while (j<n)
    {
        cout<<"cowcount 1 "<<cow_count<<endl;
        for (int i = j; i < n; i++)
        {
            if (abs(arr[i]-arr[j])>=mid)
            {
                cout<<"arr[i]"<<i<<arr[i]<<endl;
                cout<<"arr[j]"<<j<<arr[j]<<endl;
                j=i;
                cow_count++;
                cout<<"cowcount 2 "<<cow_count<<endl;
                if (cow_count == k)
                {
                    cout<<endl;
                    return true;
                }
            }
            if (cow_count > k)
            {
                return false;
            }
        }
        j++;
    }
    return false;
    // cout<<" "<<endl;
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