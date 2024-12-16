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

    // inserting naam 
    void insert(trieNode* root , string naam,string number)
    {
        if(naam.length()==0) // base case
        {
            root->isTerminal = true ;
            root->num = number;
            return ;
        }

        int index = naam[0]-'a'; // manlete hai sare naams captial hai
        trieNode* child ;
        if(root->arr[index]!=NULL) // present
        {
            child = root->arr[index];
        }
        else // absent
        {
            child = new trieNode(naam[0]);
            root->arr[index]=child;
        }
        // recursion
        insert(child,naam.substr(1), number);
        return ;
    }
    void insertnewcontact(string naam,string number)
    {
        insert(root,naam, number);
        return ;
    }

    // searching naam 
    bool search(trieNode* root,string naam)
    {
        if(naam.length()==0)
        {
            return root->isTerminal;
        }

        int index = naam[0]-'a';
        // trieNode* child ;
        if(root->arr[index]!=NULL)
        {
            return search(root->arr[index],naam.substr(1));
        }
        else
        {
            return false;
        }
    }
    bool searchnaam(string naam)
    {
        return search(root,naam);
    }

    // search with prefix

    void prefix(trieNode* root,string word ,vector<string> &ansName, vector<string> &ansNo ,bool &ekbarChalgya)
    {
        if(!ekbarChalgya)
        {
            for (int i = 0; i < word.length(); i++)
            {
                char ch = word[i];
                int index = ch-'a';
                if(root->arr[index]==NULL)
                {
                    return ;
                }
                root = root->arr[index];
            }
            ekbarChalgya = true;
        }

        if(root->isTerminal)
        {
            ansName.push_back(word);
            ansNo.push_back(root->num);
        }
        for (int i = 0; i < 26; i++)
        {
            if(root->arr[i]!=NULL)
            {
                char ch = 'a'+i;
                word.push_back(ch);
                trieNode* child = root->arr[i];
                prefix(child,word,ansName,ansNo,ekbarChalgya);
                word.pop_back();
            }
        }
        return ;
    }

    pair<vector<string>,vector<string>> searchPrefix (string word)
    {
        vector<string> ansName;
        vector<string> ansNo;
        bool ekbarChalgya = false;
        prefix(root,word,ansName,ansNo,ekbarChalgya);
        pair<vector<string>,vector<string>> p(ansName,ansNo);
        return p;
    }

};

int main()
{
    trie* phonebook = new trie();

    phonebook->insertnewcontact("piyush","9528486231");
    phonebook->insertnewcontact("piyushhome","9897387518");

    pair<vector<string>,vector<string>> ans = phonebook->searchPrefix("piyush");

    for (int i = 0; i < ans.first.size(); i++)
    {
        cout<<endl<<ans.first[i]<<" : "<<ans.second[i]<<endl;
    }
    

}