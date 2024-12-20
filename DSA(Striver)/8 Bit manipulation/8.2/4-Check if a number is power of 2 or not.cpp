class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        return  (n>0 && (n & (n-1))==0) ? true:false;
    }
};


// class Solution {
// public:
//     bool isPowerOfTwo(int n) {

        
//         for(int i =0;i<31;i++){
//         int ans = pow(2,i);
            
//             if(ans == n)return true;

//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n==0)return false;
        
//         while(n>0){
//             if(n==1)return true;
//             if(n %2 !=0)break;
//             n /=2;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         int x =1;
//         while(x<=n){
//             if(x==n)return true;
//             if(x > INT_MAX /2)break;
//             x = x<<1;
//         }
//         return false;
//     }
// };