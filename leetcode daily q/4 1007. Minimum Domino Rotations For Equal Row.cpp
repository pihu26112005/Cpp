class Solution {
    public:
        int minDominoRotations(vector<int>& top, vector<int>& b) {
            int n = top.size();
            int ans1 = 0, ans2 = 0;
            int ans3 = 0, ans4 = 0;
            int target1 = top[0], target2 = b[0];
    
            for (int i = 0; i < n; i++) {
                if (top[i] != target1 && b[i] != target1) {
                    ans1 = -1;
                    break;
                }
                if (top[i] != target1) ans1++;
            }
    
            for (int i = 0; i < n; i++) {
                if (top[i] != target2 && b[i] != target2) {
                    ans2 = -1;
                    break;
                }
                if (b[i] != target2) ans2++;
            }
    
            target1 = b[0]; // swap kr diya
            target2 = top[0];
    
             for (int i = 0; i < n; i++) {
                if (top[i] != target1 && b[i] != target1) {
                    ans3 = -1;
                    break;
                }
                if (top[i] != target1) ans3++;
            }
    
            for (int i = 0; i < n; i++) {
                if (top[i] != target2 && b[i] != target2) {
                    ans4 = -1;
                    break;
                }
                if (b[i] != target2) ans4++;
            }
    
            if (ans1 == -1 && ans2 == -1 && ans3 == -1 && ans4 == -1) return -1;
    
            if (ans1 == -1) ans1=INT_MAX;
            if (ans2 == -1) ans2=INT_MAX;
            if (ans3 == -1) ans3=INT_MAX;
            if (ans4 == -1) ans4=INT_MAX;
    
            return min({ans1,ans2,ans3,ans4});
        }
    };
    
    
    // pahle top[0] ko banane ki koshihs kr rhe hai 
    // then b[0] ko