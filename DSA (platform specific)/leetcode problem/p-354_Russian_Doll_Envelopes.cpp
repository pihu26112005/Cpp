#include<unordered_map>

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        // jinki width same hai usme se keval ek hi aayega so we neglect thatwith smaller height 
    //     unordered_map<int,bool> m;
    //     vector<vector<int>> e;
    //     for(int i=0;i<e.size();i++)
    //     {
    //         if(m[e[i][0]] = false)
    //         {
    //             e.push_back({})
    //         }
    //     }

        // sort on order of width 
            sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b) {
                return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
            });

        // then fird increasing subsequence of height

            int n = e.size();

            if(n==0)
                return 0;

            vector<vector<int>> ans;
            ans.push_back(e[0]);

            for(int i=1;i<n;i++)
                {
                    if(e[i][1]>ans.back()[1])
                    {
                        ans.push_back(e[i]);
                    }
                    else
                    {
                        int index = lower_bound(ans.begin(), ans.end(), e[i][1], [](const vector<int>& a, int height) {
                                                return a[1] < height;  // Compare based on the second element (height)
                                            }) - ans.begin();
                        ans[index]=e[i];
                    }
                }

            return ans.size();

        }
    };