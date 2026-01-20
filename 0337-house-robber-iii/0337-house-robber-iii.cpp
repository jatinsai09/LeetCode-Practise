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
    pair<int, int> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        pair<int, int> lp = dfs(root->left);
        pair<int, int> rp = dfs(root->right);

        int with = root->val + lp.second + rp.second;
        int without = max(lp.second, lp.first) + max(rp.second, rp.first);

        return {with, without};
    }
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);

        return max(res.first, res.second);
    }
};