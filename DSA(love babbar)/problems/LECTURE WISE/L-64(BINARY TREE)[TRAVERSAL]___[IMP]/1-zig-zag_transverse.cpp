#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void zig_zag_transverse(node* root , bool& firstiter)
{
    deque<node*> q;
    q.push_back(root);
    q.push_back(NULL);

    while(!q.empty()) 
    {
    if (firstiter) // ->->->->->
    {
        node* temp = q.front();
        q.pop_front();
        if(temp == NULL) \
        { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            firstiter = !firstiter ;
            if(!q.empty()) 
            { 
                //queue still has some child nodes
                q.push_front(NULL);
            }  
        }
        else
        {
        cout << temp -> data << " ";
        if(temp ->left) 
        {
            q.push_back(temp ->left);
        }
        if(temp ->right) 
        {
            q.push_back(temp ->right);
        }
        }
    }
    else // <-<-<-<-<-
    {
        node* temp = q.back();
        q.pop_back();
        if(temp == NULL) \
        { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            firstiter = !firstiter ;
            if(!q.empty()) 
            { 
                //queue still has some child nodes
                q.push_back(NULL);
            }  
        }
        else
        {
        cout << temp -> data << " ";
        if(temp ->right) 
        {
            q.push_front(temp ->right);
        }
        if(temp ->left) 
        {
            q.push_front(temp ->left);
        }
        }
    }
        
    }
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

    zig_zag_transverse(root , fir);
}
