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
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max = INT_MIN;
        return dfs(root, max);
    }
    int dfs(TreeNode* root, int max) {
        if (!root) {
            return 0;
        }

        int yes = 0;
        if (root->val >= max) {
            yes = 1;
            max = root->val;
        }

        return yes + dfs(root->left, max) + dfs(root->right, max);
    }
};