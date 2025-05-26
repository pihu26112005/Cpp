class Solution {
    public:
        int longestPalindrome(vector<string>& words) {
            int ans = 0;
            bool hasCenter = false;
            // for(string s:words){
            //     sort(s.begin(),s.end()); // this works on a copy
            // }
            unordered_map<string, int> m;
            for (string s : words) {
                m[s]++;
            }
            for (auto i : m) {
                string s = i.first;
                string rev = s;
                reverse(rev.begin(), rev.end());
                int cnt = i.second;
                cout<<s<<cnt<<endl;
                if (s == rev) {
                    // ans+=2*cnt;
                    ans += (cnt / 2) * 4;
                    if (cnt % 2 == 1)
                        hasCenter = true;
                    // same letter vali jo strings hai unke pahle 2 ke pair me
                    // process kr rhe hai fir agar odd cnt hua and end me ek bach
                    // gaya toh usko end me krenge eg - gg 3 hai and cc 5 hai pahle
                    // 2 gg ek left side ek right side then 4 cc, 2 left side 2
                    // right side ab ek gg and ek cc bacha but centre me koi ek hi
                    // aa sakta hai so abhi bas ye dekhlo ki centre me ane vala koi
                    // hai ya nhi hoga toh bas 2 add kr dena length me since unme se
                    // koi ek hi aa sakta hai
                } else if(m.count(rev)) {
                    // m.count(rev) NEEDED kyokii rev bhi hona jaruri hai map me 
                    // varna kuch bhi arbritary value de dega map 
                    ans += min(cnt, m[rev])*2;
                    // s and rev me jiska cnt kam hoga, utne string le sakte hai
                    // 2 se multiply -- taki character aa sake
                    // note hamne sirf ek baar me ek side count ki hai, ek baar same
                    // chij s ke liy count hogi and ek baar rev ke liye
                }
    
                // else if (w < s && mpp.count(s)) {
                //     count += min(freq, mpp[s]) * 4;
                // }
                // we can also do this to avoid reverse counting 
            }
            if (hasCenter)
                ans += 2;
            return ans;
        }
    };