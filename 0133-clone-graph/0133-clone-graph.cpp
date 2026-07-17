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
        unordered_map<Node*, Node*> mp;

        function<Node*(Node*)> dfs = [&](Node* cur) -> Node* {
            if (mp.count(cur)) {
                return mp[cur];
            }

            Node* copy = new Node(cur->val);
            mp[cur] = copy;
            for (auto &nbr: cur->neighbors) {
                copy->neighbors.push_back(dfs(nbr));
            }

            return copy;
        };

        return dfs(node);
    }
};