/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> r;
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();

                for (auto &child: cur->children) {
                    q.push(child);
                }

                r.push_back(cur->val);
                q.pop();
            }

            res.push_back(r);
        }

        return res;
    }
};