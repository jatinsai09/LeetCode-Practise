class Node {
private:
    Node* links[26];
    bool flag;
public:
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    Node* get(char ch) { return links[ch - 'a']; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (const auto &c: word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (const auto& c: word) {
            if (!node->containsKey(c)) {
                return false;
            }
            node = node->get(c);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (const auto &c: prefix) {
            if (!node->containsKey(c)) {
                return false;
            }
            node = node->get(c);
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