
#include "../L-62(BINARY TREE)/myclass.h"  

bool isIdentical(node *r1, node *r2)
{
     // base case
     if(r1 == NULL && r2 == NULL) {
         return true;
     }
     
     if(r1 == NULL && r2 != NULL) {
         return false;
     }
     
     if(r1 != NULL && r2 == NULL) {
         return false;
     }
     
     bool left = isIdentical(r1->left, r2->left);
     bool right = isIdentical(r1->right, r2->right);
     
     bool value = r1->data == r2->data;
     
     
     if(left && right && value) {
         return true;
     }
     else
     {
         return false;
     }
     
}