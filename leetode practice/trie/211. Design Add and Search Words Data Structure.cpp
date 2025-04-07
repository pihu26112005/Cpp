struct Node {
    Node* arr[26] = {NULL};
    bool isend = false;
};

class WordDictionary {
private:
    Node* root;
    
    bool searchHelper(string word, int index, Node* node) {
        if (!node) return false;
        if (index == word.size()) return node->isend;

        if (word[index] != '.') {
            int idx = word[index] - 'a';
            return searchHelper(word, index + 1, node->arr[idx]);
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->arr[i] && searchHelper(word, index + 1, node->arr[i])) {
                    return true;
                }
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->arr[idx] == NULL) {
                node->arr[idx] = new Node();
            }
            node = node->arr[idx];
        }
        node->isend = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
