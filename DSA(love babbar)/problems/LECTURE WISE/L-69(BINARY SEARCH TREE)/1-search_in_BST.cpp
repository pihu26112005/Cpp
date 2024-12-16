

//  BinaryTreeNode<int> * temp = root ;
//     while(temp!=NULL)
//     {
//           if(temp->data == x)
//            {
//                return true ;
//            }
        
//            if(x > temp->data)
//            {
//                temp = temp->right ;
//            }
//            else
//            {
//                temp = temp->left ;
//            }
//     }
//         return false ;



// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     // Write your code here.
//       if (root==NULL)
//     {
//         return false ;
//     }
//     if(root->data == x)
//     {
//         return true ;
//     }

//     if(x > root->data)
//     {
//         return searchInBST(root->right , x);
//     }
//     else
//     {
//         return searchInBST(root->left , x);
//     }
//     return false ;
// }