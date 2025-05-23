#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int ans = 0;

        for (auto& i : d) {
            sort(i.begin(), i.end());  
        }
        map<pair<int, int>, int> m;  
        for (auto& i : d) {
            pair<int, int> p = make_pair(i[0], i[1]);
            
            if (m.find(p) != m.end()) {
                ans += m[p];
            }
            m[p]++;
        }

        return ans;
    }
};

// behanchod ye tarike se sare pairs ka apas me banake jitn compbination banenge unka count add krna hai co khud maintain ho rha hai 
// earlier i was doing ans++ on new element 


//        unordered_map<pair<int,int>,bool> m;
// this gives error because unordered_map required hash function for custom key 
// but map has its comparator since it is implemented by red black tree