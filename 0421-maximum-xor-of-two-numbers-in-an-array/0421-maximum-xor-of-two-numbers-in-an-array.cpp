class Node {
private:
    Node* links[2];

public:
    bool containsKey(int bit) { return (links[bit] != NULL); }
    Node* get(int bit) { return links[bit]; }
    void put(int bit, Node* node) { links[bit] = node; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxXor(int num) {
        Node* node = root;
        int res = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                res |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        for (const auto& num : nums) {
            trie->insert(num);
        }

        int res = 0;
        for (const auto& num : nums) {
            res = max(res, trie->maxXor(num));
        }

        return res;
    }
};