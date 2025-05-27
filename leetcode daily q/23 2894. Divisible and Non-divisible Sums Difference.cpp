class Solution {
    public:
        int differenceOfSums(int n, int m) {
            long long totalSum = (long long)n * (n + 1) / 2;
            long long k = n / m;// Count of numbers divisible by m
            long long divisibleSum = (k * m) * (k + 1) / 2; // Sum of numbers divisible
            return (totalSum - divisibleSum) - divisibleSum; // num1 - num2
        }
    };
    
    // An arithmetic progression (AP) is a sequence like:
    // a, a + d, a + 2d, a + 3d, …
    // Where:
    // ✅ a = first term
    // ✅ d = common difference
    // ✅ n = number of terms
    // The sum of first n terms:
    // 𝑆 = [2a+(n−1)d]
    // OR
    // 𝑆 = [a+l]
    // where l = last term.
    
    // interger in range [1,n] divisible by m
    // are --> m,2m,3m,....
    // k=⌊ m/n ⌋
    // S = k/2*[m+km]