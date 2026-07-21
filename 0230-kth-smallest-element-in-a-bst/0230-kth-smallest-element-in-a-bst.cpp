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
    int kthSmallest(TreeNode* root, int k) {
        int c = 0, res = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* root) -> void {
            if (!root) {
                return;
            }

            inorder(root->left);
            c++;
            if (c == k) {
                res = root->val;
                return;
            }
            inorder(root->right);
        };
        inorder(root);
        return res;
    }
};