#include "../L-79(TRIE)/implementation_trie.h" 
#include<vector>


string longetsPrefix (vector<string> v)
{
    trie* root = new trie();

    for (int i = 0; i < v.size(); i++)
    {
        root->insertWord(v[i]);
    }    
    string ans ="";
    string s = v[0];
    root->lcp(s,ans);
}