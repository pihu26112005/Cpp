// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

class Solution {
    public:
        vector<int> ssn;
        unordered_map<string,int> dp;
        
        string encode(int i, vector<int> ssn){
            string ans = "";
            sort(ssn.begin(),ssn.end()); // this sorting is necessary 
            for(int i:ssn){
                ans+= to_string(i)+"$";
            }
            ans+= to_string(i)+"$";
            return ans;
        }
    
        int h(vector<int> &t, int i, int &st, int n){
            if(i>=n) return 0;
            
            string es = encode(i,ssn);
            if(dp.find(es)!=dp.end())
                return dp[es];
    
            int ans =INT_MAX;
    
            // start a new session from this task itself 
            ssn.push_back(t[i]);
            ans = min(ans,1+h(t,i+1,st,n));
            ssn.pop_back();
    
            // add it to any previous session if can 
            for(int j=0;j<ssn.size();j++){
                if(ssn[j]+t[i] <= st){
                    ssn[j]+=t[i];
                    ans = min(ans,h(t,i+1,st,n));
                    ssn[j]-=t[i];
                }
            }
            dp[es]=ans;
            return ans;
        }
    
        int minSessions(vector<int>& tasks, int sessionTime) {
            return h(tasks,0,sessionTime,tasks.size());
        }
    };