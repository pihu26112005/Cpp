#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });

        string result;
        for (const auto& [ch, count] : freqVec) {
            result.append(count, ch); 
        }

        return result;
    }
};
