class Solution {
    public:
        string triangleType(vector<int>& arr) {
            // sort(nums.begin(),nums.end());
            if(arr[0]+arr[1] <= arr[2] || arr[0]+arr[2] <= arr[1] || arr[1]+arr[2] <= arr[0])
                return "none";
    
            if(arr[0]==arr[1] && arr[1]==arr[2])
                return "equilateral";
            else if(arr[0]!=arr[1] && arr[1]!=arr[2] && arr[2]!=arr[0])
                return "scalene";
            else 
                return "isosceles";
        }
    };