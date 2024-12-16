#include "../L-62(BINARY TREE)/myclass.h" 

void insert_in_BST(node* &root , int input)
{
    if (root==NULL)
    {
        root = new node(input);
        return ;
    }
    
    if(input > root->data)
    {
        insert_in_BST(root->right , input);
    }
    else
    {
        insert_in_BST(root->left , input);
    }
    return ;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
    return ;
}

// int main()
// {
//     node* root = NULL;
//     int n ;
//     cin>>n;
//     while (n!=-1)
//     {
//         insert_in_BST(root , n);
//         cin>>n;
//     }

//     levelOrderTraversal(root);
// }