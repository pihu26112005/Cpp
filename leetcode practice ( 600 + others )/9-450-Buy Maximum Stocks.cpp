// https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1


class Solution {
    public:
      int buyMaximumProducts(int n, int k, int price[]) {
          // Write your code here
          vector<vector<int>> v;
          for(int i=0;i<n;i++){
              v.push_back({price[i],i+1});
          }
          sort(v.begin(),v.end());
          int ans=0;
          for(auto i:v){
              if(k<=0) break;
              
              if(i[0]*i[1] <= k){
                  ans+=i[1];
                  k-=i[0]*i[1];
              }
              else{
                  int m=k/i[0];
                  ans+=m;
                  k-=i[0]*m;
              }
          }
          return ans;
      }
  };
  