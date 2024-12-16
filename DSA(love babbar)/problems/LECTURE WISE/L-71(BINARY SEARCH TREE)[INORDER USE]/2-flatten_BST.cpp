// sirf LL nhi bnani + sorted bhi honi chahiye 

#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

void inorder(node* root , vector<int>& v) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

node* flatten (node* root)
{
     if ((root == NULL))
    {
        return NULL ;
    }
    vector<int> v ;
    inorder(root , v);

    node* first = new node(v[0]);
        node* curr = first ;
    for(int i = 1 ; i<v.size() ; i++)
    {
            node* temp = new node(v[i]);
            curr->right = temp ;
            curr = temp ;
    }

    return first ;
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//     node* mostLeft = root;
//     while(mostLeft->left !=NULL)
//     {
//         mostLeft = mostLeft->left ;
//     }

//     node *current;
//     node *pre;
//     node *post;

// 	if (root == NULL)
// 		return NULL;

// 	current = root;
// 	while (current != NULL) {

// 		if (current->left == NULL)
//         {
// 			current = current->right;
// 		}
// 		else 
//         {

    // 			pre = current->left;
    // 			while (pre->right != NULL)
    // 				{pre = pre->right;}
    //                 post = current->right ;
    //             while (pre->left != NULL)
    // 				{pre = pre->left;}

    // 			pre->right = current;
    //             pre = current;
    //             current->right = post ;
    // 			current = current->left;
    //             pre->left = NULL;
    // 		}
    // 	}
    //     return mostLeft ;
    // }