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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;

        f(root, path, res, targetSum);
        return res;
    }

    void f(TreeNode* root, auto& path, auto& res, int target) {
        if (!root) {
            return;
        }

        path.push_back(root->val);
        if (!root->left && !root->right && target == root->val) {
            res.push_back(path);
        } else {
            f(root->left, path, res, target - root->val);
            f(root->right, path, res, target - root->val);
        }

        path.pop_back();
    }
};