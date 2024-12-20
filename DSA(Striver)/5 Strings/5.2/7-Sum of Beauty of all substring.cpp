class Solution {
public:
    int ans = 0;
    int beautySum(string s) {
        // Normol approach - 2 for loop se har substring dekh lete 
        //  fir ek aur for loop se i and j ke bich me iterate krke max and min nikal lete 

        // isme two pointer nhi lag sakta tha , like usme i,j ko ek o(n) me maintai rkhne ke liye 
        // kuch chahiye hota hai like kuch cinstrain

        for (int i = 0; i < s.length(); i++) {
            map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                // counting the frequency of each character
                mp[s[j]]++;

                int leastFrequent = INT_MAX;
                int mostFrequent = INT_MIN;
                // Finding most frequent and least frequent chracter
                for (auto it : mp) {
                    leastFrequent = min(leastFrequent, it.second);
                    mostFrequent = max(mostFrequent, it.second);
                }
                ans += mostFrequent - leastFrequent;
            }
        }

        return ans;
    }
};