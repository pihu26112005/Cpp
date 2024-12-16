#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void family_chart(node* root , int& child_data , deque<int>& ans , bool firstiter)
{
    if (root == NULL)
    {
        return ;
    }
    ans.push_back(root->data);
    if (root->data == child_data)
    {
        firstiter = false;
        return ;
    }
    family_chart(root->left , child_data , ans , firstiter);
    family_chart(root->right , child_data , ans , firstiter);
    if (firstiter)
    {
        ans.pop_back();
    }
    return ;
}

int lowest_common_ancesstor(node* root , int child1 , int child2)
{
    deque<int> family1 ;
    bool firstiter ;
    deque<int> family2 ;
    bool seconditer ;
    
    family_chart(root , child1 , family1 ,firstiter);
    family_chart(root , child2 , family2 ,seconditer);

    if(family1.size()==1) // size = 1 case handle 
    {
        return family1.front();
    }
    if(family2.size()==1)
    {
        return family2.front();
    }

    int prev1;
    int prev2;
    while (!family1.empty() || !family2.empty())
    {
        prev1 = family1.front();
        prev2 = family2.front();
        family1.pop_front();
        family2.pop_front();
        if(family1.empty() || family2.empty()) // size = 2 case handle 
        {
            break;
        }
        int curr1 = family1.front();
        int curr2 = family2.front();
        if (curr1 != curr2)
        {
            break;
        }
    }
    return prev1 ;
}

int main()
{
    node* root ;
    build_tree(root);
    bool fir = true ;

    int len = 0;
    int length = -1 ;
    length_binary_tree(root , len , length);
    queue<node*> q;
    q.push(root);
    levelOrderTraversal(length , q );

    int n1 , n2 ;
    cin>>n1;
    cin>>n2;
    cout<<endl<<"ans is : "<<lowest_common_ancesstor(root , n1 , n2);
}