// video code of merge sort 

#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int c = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[c++];
    }

    c = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[c++];
    }

    //merge 2 sorted arrays     
    int a = 0;
    int b = 0;
    c = s;

    while(a < len1 && b < len2) {
        if(first[a] < second[b]) {
            arr[c++] = first[a++];
        }
        else{
            arr[c++] = second[b++];
        }
    }   
    

    while(a < len1) {
        arr[c++] = first[a++];
    }

    while(b < len2 ) {
        arr[c++] = second[b++];
    }

    delete []first;
    delete []second;

}

void merge_sort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    merge_sort(arr, s, mid);
    
    //right part sort karna h 
    merge_sort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    merge_sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}