// User function Template for C++

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = -10000000000;
         for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
                max = arr[i];
        }
        return max;
    }
};