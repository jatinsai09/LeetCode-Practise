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
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root), n = pow(2, height) - 1;

        vector<vector<string>> res(height, vector<string>(n, ""));
        res[0][(n - 1) / 2] = to_string(root->val);

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int r, int c) -> void {
            if (!root) {
                return;
            }

            if (root->left) {
                int row = r + 1, col = c - pow(2, height - r - 2);

                res[row][col] = to_string(root->left->val);
                dfs(root->left, row, col);
            }
            if (root->right) {
                int row = r + 1, col = c + pow(2, height - r - 2);

                res[row][col] = to_string(root->right->val);
                dfs(root->right, row, col);
            }
        };

        dfs(root, 0, (n - 1) / 2);
        return res;
    }
};