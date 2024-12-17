class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        vector<vector<int>> ans;
        for(auto ii: i)
        {
            // humne let say [1,3] daal diya  , ab [2,6] ya [a,b] dalna hai 
            // toh a definitely ya toh 1 ke baraber ya usse bada hoga
            // a 3 se agar kam hua , aur 1 se toh >= hoga hi, then 3 ko update krke b krdenge if nedded 
            // a agar 3 e jyada hua toh toh new interval hi bneag, tab kuch common nhi hai 

            if(ans.empty() || ii[0]>ans.back()[1])
            {
                ans.push_back(ii);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],ii[1]);
            }
            // ek saval aa sakta hia ki hum abs laste interval check kyo kr rhe hai 
            // since, new interval last vale s epiche valo se kisi se intersect hi nhi kr sakta 
        }
        return ans;
    }
};