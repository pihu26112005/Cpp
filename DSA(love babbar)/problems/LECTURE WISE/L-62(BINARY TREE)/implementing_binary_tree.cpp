#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node //class representing ek element ko 
{
    public:
    int data ;
    node* left ;
    node* right ;

    node(int d)
    {
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   // CONSTRUCTING TREE 

void build_tree(node*& NODE)// ek pointer node type ka input me liya hai and uske corresponding node create kiya hai
{
    int data ;
    cout<<"enter data or enter -1 "<<endl;
    cin>>data;
    cout<<endl;

   if (data == -1) // base case
   {
    return  ;
   }

    NODE = new node(data);
   
   cout<<"now left of "<<data<<endl;
   build_tree(NODE->left);

   cout<<"now right of "<<data<<endl;
   build_tree(NODE->right);

   return ;
}

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   // CALCULATING LENGTH OF TREE

void length_binary_tree(node* root , int& len , int& max_len)
{
    len++;
    max_len = max(max_len,len);
    if (root->left==NULL && root->right==NULL)
    {
        len--;
        return ;
    }
    else if (root->left!=NULL && root->right==NULL)
    {
        length_binary_tree(root->left , len , max_len);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        length_binary_tree(root->right , len , max_len);
    }    
    else
    {
        length_binary_tree(root->left , len , max_len);
        length_binary_tree(root->right , len , max_len);

    }
    len--;
    return ;
}

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// my algo
void levelOrderTraversal( int len , queue<node*> q )
{
    if (len == 0) // base case 
    {
        return ;
    }
    
    queue<node*> q1 ;
    queue<node*> q2 ;

    while (!q.empty())
    {
        q1.push(q.front());

        if ((q.front()->left == NULL) && (q.front()->right == NULL))
        {
            node* temp = new node(0);
            q2.push(temp);
            q2.push(temp);
        }
        else if ((q.front()->left == NULL) && (q.front()->right != NULL))
        {
            node* temp = new node(0);
            q2.push(temp);
            q2.push(q.front()->right);
        }        
        else if ((q.front()->left != NULL) && (q.front()->right == NULL))
        {
            node* temp = new node(0);
            q2.push(q.front()->left);
            q2.push(temp);
        } 
        else
        {
        q2.push(q.front()->left);
        q2.push(q.front()->right);
        }   

        q.pop();
    }
   while (!q1.empty())
   {
        for (int i = 0; i < pow(2,(len-1)); i++)
        {
            cout<<" ";
        }
        
        if (q1.front()->data == 0)
        {
            cout<<" ";
        }
        else
        {
            cout<<q1.front()->data;
        }
        
        for (int i = 0; i < pow(2,(len-1)); i++)
        {
            cout<<" ";
        }
        q1.pop();
   }
   cout<<endl;

   levelOrderTraversal(len-1 , q2 );

   return ;
}

// video algo 
// void levelOrderTraversal(node* root) {
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         node* temp = q.front();
//         q.pop();

//         if(temp == NULL) { 
//             //purana level complete traverse ho chuka hai
//             cout << endl;
//             if(!q.empty()) { 
//                 //queue still has some child ndoes
//                 q.push(NULL);
//             }  
//         }
//         else{
//             cout << temp -> data << " ";
//             if(temp ->left) {
//                 q.push(temp ->left);
//             }

//             if(temp ->right) {
//                 q.push(temp ->right);
//             }
//         }
//     }
// }

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 void transverse_for_counting_leaf( int len , queue<node* > q , int& count_leaf)
{
       if (len == 0) // base case 
    {
        return ;
    }
    
    queue<node* > q2 ;

    while (!q.empty())
    {

        if ((q.front()->left == NULL) && (q.front()->right == NULL))
        {
            count_leaf++;
        }
        else if ((q.front()->left == NULL) && (q.front()->right != NULL))
        {
            q2.push(q.front()->right);
        }        
        else if ((q.front()->left != NULL) && (q.front()->right == NULL))
        {
            q2.push(q.front()->left);
        } 
        else
        {
        q2.push(q.front()->left);
        q2.push(q.front()->right);
        }   

        q.pop();
    }

   transverse_for_counting_leaf(len-1 , q2 , count_leaf);

   return ;
}

int noOfLeafNodes(node* root)
{
    int len = 0;
    int length = -1;
    length_binary_tree(root , len , length);

    queue<node* > q;
    q.push(root);
    int count_leaf_node = 0 ;
    transverse_for_counting_leaf(length , q , count_leaf_node);

    return  count_leaf_node;
}

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// int main()
// {
//     node* root ;
//     build_tree(root);

//     int len = 0 ;
//     int length = -1 ;
//     length_binary_tree(root , len , length);
//     cout<<endl<<"length"<<length<<endl;

//     queue<node*> q;
//     q.push(root);
//     levelOrderTraversal(length , q );
// }