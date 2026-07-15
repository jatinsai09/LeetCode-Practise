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
    int sum = 0;
    void f(TreeNode* node, int val) {
        val = val * 10 + node->val;
        if (!node->right && !node->left) {
            sum += val;
            return;
        }
        if (node->left) {
            f(node->left, val);
        }
        if (node->right) {
            f(node->right, val);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        f(root, 0);
        return sum;
    }
};