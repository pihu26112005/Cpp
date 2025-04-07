class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> s;
            int n = path.size();
            int i = 0;
            
            while (i < n) {
                // Skip multiple slashes
                while (i < n && path[i] == '/') i++;  
                if (i >= n) break;  
                
                int start = i;
                while (i < n && path[i] != '/') i++;
                string dir = path.substr(start, i - start);
                
                if (dir == "..") {  
                    if (!s.empty()) s.pop(); 
                } 
                else if (dir != ".") {  
                    s.push(dir);  
                }
            }
            
            string ans = "";
            while (!s.empty()) {
                ans = "/" + s.top() + ans;
                s.pop();
            }
            
            return ans.empty() ? "/" : ans;
        }
    };
    
    
    // "/" handle alternatively bhi kr sakte hai 
    // - jab bhi "/" dikhe toh ek baar "/" push krdo 
    // - fir jab tak "/" dikhe i++ krte rho 
    
    // isme "/" end me khudse add kiye hai 