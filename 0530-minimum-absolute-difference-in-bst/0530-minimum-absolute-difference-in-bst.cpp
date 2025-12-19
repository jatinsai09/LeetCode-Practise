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
    int getMinimumDifference(TreeNode* root) {
        int res = 1e6, prev = -1;

        function<void(TreeNode*)> inorder = [&](TreeNode* root) -> void {
            if (!root) {
                return;
            }

            inorder(root->left);

            if (prev != -1) {
                res = min(res, root->val - prev);
            }
            prev = root->val;

            inorder(root->right);
        };

        inorder(root);
        return res;
    }
};