class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        // here we will use optimized version of two pointer on 2 sum
        // it is in o(n) tc not o(n square) and o(1) space

        int i=0;
        int j=num.size()-1;
        while(i<j){
            if(num[i]+num[j]==t) return {i+1,j+1};
            else if(num[i]+num[j]>t) j--;
            else i++;
        }
        return {};
    }
};