#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 
 // SC - O(N+M)

void inorder(node* root , vector<int>& v) 
{
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

vector<int>  merge (vector<int> arr1 , vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr3 ;
    int a = 0 , b = 0 , c = 0 ;
    while (a<n & b<m)
    {
        if (arr1[a]<arr2[b])
        {
            arr3[c]=arr1[a];
            c++;
            a++;
        }
        else
        {
            arr3[c]=arr2[b];
            c++;
            b++;
        }
    }
    while (a<n)
    {
        arr3[c]=arr1[a];
        c++;
        a++;
    }
    while (b<m)
    {
        arr3[c]=arr2[b];
        c++;
        b++;
    }
    return arr3 ;
}
