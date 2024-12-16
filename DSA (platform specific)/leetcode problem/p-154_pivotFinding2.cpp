// find minimum element of rotated sorted array 
// but elements can be repeated

// slightli updated version of previus code

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0, start = 0;
        int e = n - 1, end = n - 1;
        // if(arr.size()==2 && (arr[0]>arr[1])) // for case [3,1]
        //     return arr[1];
        int mid = start + (end - start) / 2;
        // to find pivot element
        while (start < end) {
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            } else if (arr[mid] < arr[end]) {
                end = mid;
            }
            else {
                end--;
            }
            mid = start + (end - start) / 2;
        }
        // cout<<"start"<<start;
        // if(arr[start]<arr[0]) // for case -- sorted array me pivot last element deta hai
            return arr[start];
        // return arr[0];
    }
};