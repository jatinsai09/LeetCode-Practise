/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        // postorder(root, res);
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* last = NULL;

        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* node = st.top();

                if (node->right && last != node->right) {
                    cur = node->right;
                } else {
                    res.push_back(node->val);

                    last = node;
                    st.pop();
                }
            }
        }

        return res;
    }

    void postorder(TreeNode* node, vector<int>& res) {
        if (node == NULL) {
            return;
        }

        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }
};