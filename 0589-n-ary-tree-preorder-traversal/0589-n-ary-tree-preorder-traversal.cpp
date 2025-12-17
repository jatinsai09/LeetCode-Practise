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
    vector<int> preorder(Node* root) {
        vector<int> res;

        function<void(Node*)> traverse = [&](Node* root) -> void {
            if (root == nullptr) {
                return;
            }

            res.push_back(root->val);

            for (const auto &child: root->children) {
                traverse(child);
            }
        };

        traverse(root);

        return res;
    }
};