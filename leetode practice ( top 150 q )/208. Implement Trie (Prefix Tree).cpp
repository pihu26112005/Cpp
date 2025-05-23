struct Node {
    Node* link[26];
    int yahaTakKitneEnd =0;// prefix 
    int yahaPeKitneWordEnd =0;// end 
    // ye dono root node ke liye insignificant hai 

    Node() {  
        for (int i = 0; i < 26; i++)  
            link[i] = NULL;  
    } 
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(node->link[idx]!=NULL){
                node = node->link[idx];
            }
            else{
                node->link[idx] = new Node;
                node = node->link[idx];
            }
            node->yahaTakKitneEnd++;
        }
        node->yahaPeKitneWordEnd++;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(node->link[idx]!=NULL){
                node = node->link[idx];
            }
            else{
                return false;
            }
        }
        return (node->yahaPeKitneWordEnd > 0);
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(node->link[idx]!=NULL){
                node = node->link[idx];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */