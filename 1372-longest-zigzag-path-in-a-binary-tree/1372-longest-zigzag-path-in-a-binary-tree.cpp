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
    int dfs(TreeNode* root, int dir, int& res) {
        int l = 0, r = 0;

        if (root->left) {
            l = 1 + dfs(root->left, 0, res);
        }

        if (root->right) {
            r = 1 + dfs(root->right, 1, res);
        }

        res = max({res, l, r});

        return (dir ? l : r);
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;

        dfs(root, -1, res);

        return res;
    }
};