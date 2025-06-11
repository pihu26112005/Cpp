// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/

class Solution {
    public:
        bool canAssign(int mid, int i, vector<int> w, vector<int> &jobs){
            if(i==jobs.size()) return true;
    
            for(int j=0;j<w.size();j++){
                if(w[j]+jobs[i] <= mid){
                    w[j]+=jobs[i];
                    if(canAssign(mid,i+1,w,jobs))
                        return true;
                    w[j]-=jobs[i];
                }
                if(w[j]==0) // basically abhi jo worker ko assing kiya tha vo pahli baar aaay tha so next bhi 0 hoga
                    break;
            }
            return false;
        }
        int minimumTimeRequired(vector<int>& jobs, int k) {
            int n=jobs.size();
            vector<int> w(k,0); //workers 
            int s=0;
            int e=0;
            for(int i:jobs){
                s=max(s,i);
                e+=i;
            }
            int m=s+(e-s)/2;
            int ans=-1;
            while(s<=e){
                m=s+(e-s)/2;
                if(canAssign(m,0,w,jobs)){
                    ans=m;
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            return ans;
        }
    };