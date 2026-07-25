class Node {
    Node* links[2];

public:
    bool containsKey(int bit) { return (links[bit] != NULL); }
    void put(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
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
            int bit = ((num >> i) & 1);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        Trie* trie = new Trie();

        sort(begin(nums), end(nums));
        
        vector<int> qind(q);
        iota(begin(qind), end(qind), 0);

        sort(begin(qind), end(qind),
             [&](int i, int j) { return queries[i][1] < queries[j][1]; });
             
        vector<int> res(q);
        for (int i = 0, j = 0; i < q; i++) {
            while (j < n && nums[j] <= queries[qind[i]][1]) {
                trie->insert(nums[j++]);
            }
            
            if (j == 0) {
                res[qind[i]] = -1;
                continue;
            }

            res[qind[i]] = trie->maxXor(queries[qind[i]][0]);
        }

        return res;
    }
};