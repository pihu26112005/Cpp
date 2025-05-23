class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
            vector<int> diff(nums.size() + 1, 0);
            for(int i = 0; i < q.size(); i++) { // creating diff array
                diff[q[i][0]]++;
                diff[q[i][1] + 1]--;
            }
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += diff[i]; // taking prefix sum up to i
                if(nums[i] > sum)
                    return false;
            }
            return true;
        }
    };
    
    // brute force -- ys 
    
    // what i know ki kisi trah agar ye pata laga le ki arr[i] pr kitni baar decremenet hoga then we can say in o(n) ki sare number zero ban sakte hai ya nhi 
    // so first traverse over queries --> to make his array jo batayegi ki arr[i] me kitne decrement 
    // then o(n) me ans 
    
    // ----------------------------------------------------------------------------------------
    //💡 Difference Array Trick Explained
    //Normally, if you want to increase elements from l to r by 1, you'd do a loop from l to r — O(n×q) time.
    
    //But with the difference array, we do:
    // diff[l] += 1;
    // diff[r + 1] -= 1;
    // Then, when we take the diff sum over the diff array, we get the total increment at each position.
    // --------------------------------------------------------------------------------------------