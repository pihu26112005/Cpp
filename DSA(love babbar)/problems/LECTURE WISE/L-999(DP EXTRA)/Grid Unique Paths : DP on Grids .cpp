https://leetcode.com/problems/unique-paths/description/
https://www.naukri.com/code360/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Solution {
public:
    // Helper function to calculate factorial recursively
    // long factorial(long num) {
    //     if (num <= 1) return 1; // Base case
    //     return num * factorial(num - 1); // Recursive case
    // }
    
    // int uniquePaths(int m, int n) {
    //     // Calculate the factorial-based result (m+n-2)! / ((m-1)! * (n-1)!)
    //     long totalSteps = m + n - 2; // Total steps needed
    //     long downSteps = m - 1;     // Steps down
    //     long rightSteps = n - 1;    // Steps right

    //     // Using the formula (m+n-2)! / ((m-1)! * (n-1)!)
    //     long ans =  factorial(totalSteps) / (factorial(downSteps) * factorial(rightSteps));
    //     return (int) ans;
    // }

    // pure factorial nikalne me integer overflow ho rha hai, so fomula khol ke final solve krlo 
    int uniquePaths(int m, int n) {
        long result = 1;
        int totalSteps = m + n - 2; 
        int stepsToChoose = min(m - 1, n - 1); 

        for (int i = 1; i <= stepsToChoose; ++i) {
            result *= totalSteps--; 
            result /= i;            
        }
        return (int)result;
    }
};