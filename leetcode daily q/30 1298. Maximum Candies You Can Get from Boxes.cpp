class Solution {
    public:
        int maxCandies(vector<int>& s, vector<int>& c, vector<vector<int>>& k,
                       vector<vector<int>>& cb, vector<int>& ib) {
            if (ib.size() == 0)
                return 0;
    
            queue<int> q;
            vector<int> vis(s.size(), 0);
            vector<int> boxMila(s.size(), 0);
            int ans = 0;
            for (int i : ib) {
                boxMila[i] = 1;
                if (s[i] == 1) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
    
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    int b = q.front();
                    q.pop();
    
                    if (s[b] == 0)
                        continue;
    
                    ans += c[b];
    
                    // first take all inside keys and open new boxes
                    for (int key : k[b]) {
                        s[key] = 1;
                        // key mili hai toh sirf status hi 1 kr sakta hun, open nhi
                        // kr sakta hai open tabhi kr sakta hu jab pahle mila tha
                        // kahin
                        if (vis[key] == 0 && boxMila[key] == 1) {
                            q.push(key);
                            vis[key] = 1;
                        }
                    }
    
                    // opening contained boxes if open
                    for (int inbox : cb[b]) {
                        boxMila[inbox] = 1; // box mil gaya hai
                        // ab agar status 1 hai toh abhi kholdo, varna badme jab key
                        // mil jaaye toh khol lunga ' but i need to track na ki ye
                        // box past me mila tha
                        if (vis[inbox] == 0 && s[inbox] == 1) {
                            q.push(inbox);
                            vis[inbox] = 1;
                        }
                    }
                }
            }
            return ans;
        }
    };
    
    // jab tak box khud nhi milega nhi khol sakta
    // key se sirf uska status change kr sakte hai
    // contained box batayega ki mughe konse box mile hai, open only is status 1 hai
    
    // key milgayi toh status open kr sakte hai bas
    // box inside jo hain, agar unka status open hai toh instantly use kr sakte hai
    // but agar status closed hai, toh unko abhi nhi open kr sakte hai, but there
    // may be case ki koi dusra box inka status open krde and tab inko use kr sakte
    // hai, bhale hi ye us box me contained na ho