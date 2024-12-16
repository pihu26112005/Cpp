#include<iostream>
#include<vector>
using namespace std ;

class trieNode
{
    public :
    char data;
    bool isTerminal;
    char childcount;
    trieNode* arr[26];

    trieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            arr[i]=NULL;
        }
        isTerminal=false;
    }
};

class trie
{
    public :
    trieNode* root;

    trie()
    {
        root = new trieNode('\0');
    }

    void lcp(string v , string &ans)
    {
        for (int i = 0; i < v.length(); i++)
        {
            char ch = v[i];
            if(root->childcount==1)
            {
                ans.push_back(ch);
                int index = ch-'a';
                root = root->arr[index]; // kyooki by reference pass nhi kiya toh root ko change krne ka koi farak nhi pdega
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
        return ;
    }

    // inserting word 
    void insert(trieNode* root , string word)
    {
        if(word.length()==0) // base case
        {
            root->isTerminal = true ;
            return ;
        }

        int index = word[0]-'A'; // manlete hai sare words captial hai
        trieNode* child ;
        if(root->arr[index]!=NULL) // present
        {
            child = root->arr[index];
        }
        else // absent
        {
            child = new trieNode(word[0]);
            root->arr[index]=child;
        }
        // recursion
        insert(child,word.substr(1));
        return ;
    }
    void insertWord(string word)
    {
        insert(root,word);
        return ;
    }

    // searching word 
    bool search(trieNode* root,string word)
    {
        if(word.length()==0)
        {
            return root->isTerminal;
        }

        int index = word[0]-'A';
        // trieNode* child ;
        if(root->arr[index]!=NULL)
        {
            return search(root->arr[index],word.substr(1));
        }
        else
        {
            return false;
        }
    }
    bool searchWord(string word)
    {
        return search(root,word);
    }


    void delet(trieNode* &root , string word)
    {
        if(word.length()==0) // base case
        {
            if(root->isTerminal)
            {
              root->isTerminal = false ;
            }
            return ;
        }

        int index = word[0]-'a'; // manlete hai sare words captial hai
        trieNode* child ;
        if(root->arr[index]!=NULL) // present
        {
            child = root->arr[index];
            delet(child,word.substr(1));
        }
        return ;
    }

    void erase(string &word)
    {
        // Write your code here.
        delet(root,word);
        return ;
    }
};