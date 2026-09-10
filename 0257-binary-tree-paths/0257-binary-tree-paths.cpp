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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s = "";

        function<void(TreeNode*, string)> dfs = [&](TreeNode* root, string s) -> void {
            s += to_string(root->val);

            if (!root->left && !root->right) {
                res.push_back(s);
                return;
            }

            s += "->";
            if (root->left) {
                dfs(root->left, s);
            }
            if (root->right) {
                dfs(root->right, s);
            }
        };
        dfs(root, s);
        
        return res;
    }
};