/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> f;
        int mxc = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) -> void {
            if (!node) {
                return;
            }

            inorder(node->left);

            int c = ++f[node->val];

            if (c > mxc) {
                mxc = c;
                res.clear();
                res.push_back(node->val);
            } else if (c == mxc) {
                res.push_back(node->val);
            }

            inorder(node->right);
        };

        inorder(root);
        return res;   
    }
};