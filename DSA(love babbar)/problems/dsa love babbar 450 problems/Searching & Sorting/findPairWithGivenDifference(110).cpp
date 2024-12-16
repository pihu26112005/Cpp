#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

// TC-O(NLOG(N))  SC-O(N);
bool findPair(int arr[], int size, int n){
    //code
    map<int,int> m;
    std::sort(arr, arr + size);  // Use std::sort
    for(int i=0;i<size;i++)
    {
        m[arr[i]]++;
        m[arr[i]+n]++;
        if(m[arr[i]]==2)
            return true;
    }
    return false;
}

// TC-O(NLOG(N))  SC-O(1);
// 2 POINTER APPROACH
bool findPair(int arr[], int size, int n){
   sort(arr,arr+size);
int i=0; 
int j=1;
while(i<size && j<size){
   if(i!=j && arr[j]-arr[i]==n){
        return true;
   }
   else if( arr[j]-arr[i]<n){
        j++;
   }
   else{
        i++;
   }
}
return false;
}