
#include "../L-62(BINARY TREE)/myclass.h" 

node* deleteNode(node* root, int key) {
    // Write your code here.
    node* temp = root ;
    if(temp == NULL)
    {
        return root ;
    }

    if(key==temp->data)
    {
             if(temp->left==NULL && temp->right==NULL)
            {
                delete temp;
                return NULL;
            }
            else if(temp->left!=NULL && temp->right==NULL)
            {
                node* x = temp->left ;
                delete temp ;
                return x ;
            }
            else if(temp->left==NULL && temp->right!=NULL)
            {
                node* x = temp->right ;
                delete temp ;
                return x ;
            }
            else 
            {
                node* min = temp->left ;
                while(min->right!=NULL)
                {
                    min=min->right ;
                }
                temp->data = min->data ;
                temp->left = deleteNode(temp->left , min->data);
                return root ;
            }
    }   
    if(key>temp->data)
    {
        temp->right =deleteNode( temp->right , key );
    }
    else
    {
        temp->left =deleteNode( temp->left , key);
    }
    
        // temp = delet(temp);
    
    
    return root ;
}
