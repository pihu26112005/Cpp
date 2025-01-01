bool static comp(vector<int> a, vector<int> b) {
         double r1 = (double) a[0] / (double) a[1];
         double r2 = (double) b[0] / (double) b[1];
         return r1 > r2;
}

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({val[i],wt[i]});
        }
        
        sort(arr.begin(),arr.end(), comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i][1] <= W) {
            curWeight += arr[i][1];
            finalvalue += arr[i][0];
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i][0] / (double) arr[i][1]) * (double) remain;
            break;
         }
      }

      return finalvalue;
    }