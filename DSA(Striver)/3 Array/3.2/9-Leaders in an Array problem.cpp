class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        ans.push_back(arr[arr.size()-1]);
        int m = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i]>=m)
                ans.push_back(arr[i]);
            m = max(m,arr[i]);
        }
        // reversing ans array 
        int i=0;
        int j=ans.size()-1;
        while(i<j)
        {
            int t = ans[i];
            ans[i]=ans[j];
            ans[j]=t;
            i++;
            j--;
        }
        return ans;
    }