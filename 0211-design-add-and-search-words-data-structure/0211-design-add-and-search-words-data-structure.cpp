struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class WordDictionary {
private: 
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (const auto &ch: word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {

        function<bool(int, Node*)> dfs = [&](int i, Node* node) -> bool {
            if (i == word.size()) {
                return node->isEnd();
            }

            char ch = word[i];
            if (ch == '.') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (node->containsKey(c)) {
                        if (dfs(i + 1, node->get(c))) {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (!node->containsKey(ch)) {
                return false;
            }
            return dfs(i + 1, node->get(ch));
        };

        return dfs(0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */