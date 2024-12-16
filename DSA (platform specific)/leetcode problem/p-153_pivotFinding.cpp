// pivot - least element in array 
// array type - rotated array of sorted array (inctreasing )
// array - {0,1,2,3,4,5,6,7,8,9}
// rotaed array - {6,7,8,9,0,1,2,3,4,5}


class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int k = 9;
        int s = 0, start = 0;
        int e = n - 1, end = n - 1;
        // if(arr.size()==2 && (arr[0]>arr[1]))
        //     return arr[1];
        int mid = start + (end - start) / 2;
        // to find pivot element
        while (start < end) {
            if (arr[mid] >= arr[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        // cout<<"start"<<start;
        // if(arr[start]<arr[0])
            return arr[start];
        // return arr[0];
    }
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// from love babbar video

#include<iostream>
using  namespace std ;
int main()
{
    // using binary search  , time - o(log(n))
    int a[10] = {6,7,8,9,0,1,2,3,4,5};
    int s = 0;
    int e = 9;
    int m = s + (e-s)/2;
    if(a.size()==2 && (a[0]>a[1]))
            return a[1]; // for case [3,1]
    while (s<e)
    {
        if (a[m]>=a[e])
        {
            s=m+1;
        }
        else
        {
            e=m;
        }
        m = s + (e-s)/2;
    }
    if(a[s]<a[0])
            return a[s]; // for case -- sorted array me pivot lat element deta hai
        return a[0]; // normol case 

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // using normal for loop time - o(n)
    int j=0;
    for (int i = 1; i < 10; i++)
    {
        if (a[i]>a[i-1])
        {
            j++;
        }
        else
        {
            break;
        }
    }
    cout<<j+1<<endl;
}