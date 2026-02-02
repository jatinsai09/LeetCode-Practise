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
    bool findTarget(TreeNode* root, int k) { return dfs(root, root, k); }

    bool dfs(TreeNode* root, TreeNode* cur, int k) {
        if (!cur) {
            return false;
        }
        
        return find(root, cur, k - cur->val) || dfs(root, cur->left, k) ||
               dfs(root, cur->right, k);
    }

    bool find(TreeNode* root, TreeNode* cur, int val) {
        if (!root) {
            return false;
        }

        if (root->val == val && root != cur) {
            return true;
        }

        return find(root->left, cur, val) || find(root->right, cur, val);
    }
};