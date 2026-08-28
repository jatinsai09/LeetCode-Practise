/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        unordered_map<Node*, Node*> mp; // og -> copy

        function<Node*(Node*)> dfs = [&](Node* cur) -> Node* {
            if (mp.find(cur) != mp.end()) {
                return mp[cur];
            }

            Node* copy = new Node(cur->val);
            mp[cur] = copy;

            for (const auto &nbr: cur->neighbors) {
                copy->neighbors.push_back(dfs(nbr));
            }

            return copy;
        };

        return dfs(node);
    }
};