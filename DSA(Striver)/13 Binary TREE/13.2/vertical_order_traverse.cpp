#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;

template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

/************************************************************************************************************************************************************************************/

bool customComparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    // Sort in decreasing order of second values
    if (a.second != b.second) {
        return a.second > b.second;
    }
    
    // If second values are the same, sort in decreasing order of first values
    return a.first < b.first;
}

void vertical_transverse(deque<pair<TreeNode<int>*,pair<int,int>>> d , map<int,deque<pair<int,int> >>& m , vector<int> &ans ) 
{
    int maxCount = -1;
    int minCount = 10000;
    int size = d.size();
    while (!d.empty())
    {
        TreeNode<int>* root = d.front().first;
        int count = d.front().second.first; // xcordinate
        int ycord = d.front().second.second; // ycordinate
        d.pop_front();

        pair<int,int> p = make_pair(root->data,ycord); // rrot.data , uska y cordinate
        m[count].push_back(p); // same x cordinate vale ek sath 
        maxCount = max(maxCount,count);
        minCount = min(minCount,count);
        if (root->right)
        {
            int right_count = count+1; // right ka x cord
            int right_ycord = ycord-1; // right ka y cord
            pair<TreeNode<int>* , pair<int,int>> right_node(root->right,make_pair(right_count,right_ycord));
            d.push_back(right_node);
        }
        if (root->left)
        {
            int left_count = count-1; // left ka x cord
            int left_ycord = ycord-1; // left ka y cord
            pair<TreeNode<int>* , pair<int,int>> left_node(root->left,make_pair(left_count,left_ycord));
            d.push_back(left_node);
        }
    }   

    for(int i=minCount;i<=maxCount;i++)
    {
        deque<pair<int,int>> temp = m[i];
        sort(temp.begin(), temp.end(), customComparator);
        while(!temp.empty())
        {
            int element = temp.front().first;
            temp.pop_front();
            ans.push_back(element);
        }
    }

    return ;
}


vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    map<int,deque<pair<int,int>>> m;
    int count = 0;
    int ycord = 0;
    pair<TreeNode<int>*,pair<int,int>> p(root,make_pair(count,ycord));
    deque<pair<TreeNode<int>*,pair<int,int>>> d;
    d.push_back(p);
    vertical_transverse(d, m , ans );

    return ans;

}