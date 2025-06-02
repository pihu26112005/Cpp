// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    public:
      vector<int> diagonal(Node *root) {
          // code here
          vector<int> ans;
          
          queue<Node*> q;
          q.push(root);
          
          while(!q.empty()){
              int s=q.size();
              for(int i=0;i<s;i++){
                  Node* t=q.front();
                  q.pop();
                  
                  while(t!=NULL){
                      ans.push_back(t->data);
                      if(t->left)
                          q.push(t->left);
                      t=t->right;
                  }
              }
          }
          return ans;
          
      }
  };