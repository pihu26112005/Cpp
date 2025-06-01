class Solution {
    public:
        long long cal(int x) {
            if (x < 0) {
                return 0;
            }
            return (long)x * (x - 1) / 2;
        }
    
        long long distributeCandies(int n, int limit) {
            return cal(n + 2) - 3 * cal(n - limit + 1) +
                   3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
        }
    };
    
    // C(n+2,2)  −  3×C(n−(limit+1)+2,2)  +  3×C(n−2×(limit+1)+2,2)  −  C(n−3×(limit+1)+2,2)
    // total  -  casA  +  caseB  -  caseC   
    // Total distributions (no restriction)
    // At least one child exceeds
    // At least two children exceed
    // All three exceed
    
    // and 
    // C(x,2) = x(x-1)/2