#include<iostream>
#include<vector>
using namespace std;

int missingK(vector < int > vec, int n, int k) {

    int i=0,j=n-1;

    while(i<=j)

    {

        int mid=i+(j-i)/2;

        int missing=vec[mid]-mid-1;

        if(missing<k)
            i=mid+1;

        else 
            j=mid-1;

    }

    return i+k;

}

// basically start = 0 , end = n-1 first , last index of arr
// it calculates mid index , then 
// check number of mission numbers before arr[mid]
// after loop , i represent index of element where the number of missing elements is greater than or equal to k
// This is the point where the kth missing number should be inserted into the array.