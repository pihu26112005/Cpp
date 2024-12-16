#include<vector>
// o(logn) solution

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return arr[0];
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {

            if(mid-1>=0 && mid+1<n && arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) {
                return arr[mid];
            }
            else if(mid-1<0 && mid+1<n && arr[mid]!=arr[mid+1]) {
                return arr[mid];
            }
            else if(mid-1>=0 && mid+1>=n && arr[mid]!=arr[mid-1]) {
                return arr[mid];
            }

            else if(mid+1<n && arr[mid] == arr[mid+1]) {
                int l = mid - start;
                int r = end - (mid+1);
                if(r%2 != 0)
                    start = mid+2;
                else
                    end = mid-1;
            }
            else if(mid-1>=0 && arr[mid] == arr[mid-1]) { 
                int l = mid-1 - start;
                int r = end - (mid);
                if(r%2 != 0)
                    start = mid+1;
                else
                    end = mid-2;
            }

            mid = start + (end-start)/2;
        }
        
        return -1;
    }
};