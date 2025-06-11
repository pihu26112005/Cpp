
// https://leetcode.com/problems/previous-permutation-with-one-swap/

class Solution {
    public:
        vector<int> prevPermOpt1(vector<int>& arr) {
            int n=arr.size();
            int i=n-2;
            while(i>=0 && arr[i] <= arr[i+1]){
                i--;
            }
            if(i==-1){
                // puri array increasing hai 
                return arr;
            }
            
            int j=i+1; // optimization, skipping one iteration
            int justSmallerThanI = i+1;
            while(j<n){
                if(j < n && arr[j]<arr[i] && arr[j]>arr[justSmallerThanI]){
                    justSmallerThanI=j;
                }
                j++;
            }
            swap(arr[i],arr[justSmallerThanI]);
            return arr;
        }
    };
    // 