#include<iostream>
#include<vector>
using namespace std ;

class trieNode
{
    public :
    char data;
    bool isTerminal;
    string num;
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

    // 
    void printSuggestion(vector<string> &temp , trieNode* curr , string prefix )
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for(char ch='a';ch<='z';ch++)
        {
            int index = ch-'a';
            trieNode* next = curr->arr[index];
            if(next!=NULL)
            {
                prefix.push_back(ch);
                printSuggestion(temp,curr,prefix);
                prefix.pop_back();
            }
        }
        return ;
    }

    vector<vector<string>> getSuggestion(string str)
    {
        trieNode* prev = root;
        vector<vector<string>> output ;
        string prefix ;

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            int index = lastch-'a';
            trieNode* curr = prev->arr[index];

            if(curr==NULL)
            {
                break;
            }

            vector<string> temp;
            printSuggestion(temp,curr,prefix);

            output.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return output;
    }

};

