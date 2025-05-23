/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        void h(Node* na, Node* nb){
            if(na==NULL && nb==NULL) return ;
    
            na->next=nb;
            nb->next=NULL;
    
            h(na->left,na->right);
            h(na->right,nb->left);
            h(nb->left,nb->right);
    
            return;
        }
    
        Node* connect(Node* root) {
    
            if (root == NULL) return NULL;
    
            root->next=NULL;
    
            h(root->left,root->right);
    
            return root;
        }
    };