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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* newRoot = root;

        function<void(TreeNode*)> inorder = [&](TreeNode* root) -> void {
            if (!root) {
                return;
            }

            inorder(root->left);
            root->left = NULL;

            if (prev) {
                prev->right = root;
            } else {
                newRoot = root;
            }
            prev = root;

            inorder(root->right);
        };

        inorder(root);

        return newRoot;
    }
};