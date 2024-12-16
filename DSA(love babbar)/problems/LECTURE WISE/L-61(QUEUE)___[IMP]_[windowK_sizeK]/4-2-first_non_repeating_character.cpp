// ek string ke corresponding ek string return krni hai jisme first non repeating characters hone chahiye 
// ex : aabc me a --> a , aa --> # , aab --> b , aabc --> b 
// ans of aabc --> a#bb

// code studio pe nhi hai 

#include<iostream>
#include<queue>
#include<deque>
#include<map>
using namespace std;

string FirstNonRepeating(string A){
		    map<char, int> m;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
