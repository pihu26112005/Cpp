class Solution {
    public:
        Node* connect(Node* root) {
            if (!root) return NULL;
    
            queue<Node*> q;
            q.push(root);
    
            while (!q.empty()) {
                int size = q.size();
                Node* prev = NULL;
    
                for (int i = 0; i < size; ++i) {
                    Node* curr = q.front();
                    q.pop();
    
                    if (prev) {
                        prev->next = curr;
                    }
                    prev = curr;
    
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
    
                prev->next = NULL;
            }
    
            return root;
        }
    };
    
    
    // BFS se do min me ho jata 