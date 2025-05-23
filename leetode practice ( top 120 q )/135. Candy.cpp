// my approach giving tle 
class Solution {
public:
    int candy(vector<int>& r) {
        if(r.size()==0) return 0;
        if(r.size()==1) return 1;
        if(r.size()==2){
            if(r[0]==r[1]) return 2;
            return 3;
        }
        unordered_map<int,int> m;
        int ans = 0;
        int lc = 0;
        if(r[0]>=r[1]){
            lc=1;
            if(r[0]==r[1]) ans+=2;
            else ans+=3;
        }
        else{
            lc=2;
            ans+=3;
        }
        for(int i=2;i<r.size();i++){
            if(r[i-1]==r[i]){
                lc=1;
                ans++;
            }
            else if(r[i-1]>r[i]){
                if(lc==1){
                    int j=i-1;
                    while(j>=0){
                        if( j>0 && r[j-1]<=r[j]){
                            // cout<<i<<"whileIf"<<ans<<endl;
                            ans++;
                            m[j]++;
                            break;
                        }
                        else{
                            // cout<<i<<"whileElse"<<ans<<endl;
                            ans++;
                            m[j]++;
                            if((m[j-1]-(m[j]-1))>1)
                                break;
                        }
                        j--;
                    }
                    lc=1;
                    ans++;
                }
                else{
                    lc=1;
                    ans++;
                }
            }
            else{
                lc++;
                ans+=lc;
            }
            m[i]=lc;
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};

// --------------------------------------------------------------------------------------------------------------------------

// 1- striver ki left right approach 
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

// 2 - striver ki slope using approach 
class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
        int totalCandies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int currentPeak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                currentPeak++;
                totalCandies += currentPeak;
                i++;
            }

            if (i == n) {
                return totalCandies;
            }

            int currentValley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                currentValley++;
                totalCandies += currentValley;
                i++;
            }

            totalCandies -= min(currentPeak, currentValley);
        }

        return totalCandies;        
    }
};