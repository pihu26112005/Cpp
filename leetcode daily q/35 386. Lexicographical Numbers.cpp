// class Solution {
// public:
//     void h(int i, int &n, vector<int> &ans){
//         if(i>n)
//             return;

//         for(int j=0;j<=9;j++){
//             if(i+j<=n){
//                 ans.push_back(i+j);
//                 h((i+j)*10,n,ans);
//             }
//         }
//         return;
//     }
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         h(1,n,ans);
//         return ans;
//     }
// };

// class Solution {
// public:
//     void h(int i, int& n, vector<int>& ans) {
//         if (i > n)
//             return;

//         for (int j = 0; j <= 9; j++) {
//             if (i + j <= n) {
//                 ans.push_back(i + j);
//                 h((i + j) * 10, n, ans);
//             }
//         }
//         return;
//     }
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         if (n < 10) {
//             for (int i = 1; i <= n; i++)
//                 ans.push_back(i);
//             return ans;
//         }
//         // else
//         for (int i = 1; i < 10; i++) {
//             ans.push_back(i);
//             h(i*10, n, ans);
//         }
//         return ans;
//     }
// };


class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            vector<int> ans;
            int curr = 1;
    
            for (int i = 0; i < n; i++) {
                ans.push_back(curr);
    
                if (curr * 10 <= n) {
                    curr *= 10;
                } else {
                    while (curr % 10 == 9 || curr + 1 > n)
                        curr /= 10;
                    curr++;
                }
            }
    
            return ans;
        }
    };
    
    // although last vala recursive stack me O(n) le rha tha 
    // so this one is for iterative loop for recursive stack 