/// very easy

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        int j=0;
        int c=1;
        int n = arr.size();
        while(c<=k)
        {
            if((j<n && i<arr[j]) || j>=n)
            {
                c++;
                i++;
            }
            else
            {
                j++;
                i++;
            }
        }
        return i-1;
    }
};