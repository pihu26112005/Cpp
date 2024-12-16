// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        int largest = -1;
        int seclargest = -1;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                seclargest = largest;
                largest = arr[i];
            }else if(arr[i] > seclargest && arr[i] != largest){
                seclargest  = arr[i];
            }
            
        }
        
        return seclargest;
    }
};