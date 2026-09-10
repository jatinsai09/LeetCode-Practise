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
    string smallestFromLeaf(TreeNode* root) {
        string res, s = "";

        function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
            if (!root) {
                return;
            }

            s.push_back(char('a' + root->val));

            if (!root->left && !root->right) {
                string got = s;
                reverse(begin(got), end(got));

                if (res.empty() || got < res) {
                    res = got;
                }
                s.pop_back();
                return;
            }

            dfs(root->left);
            dfs(root->right);

            s.pop_back();
        };
        dfs(root);

        return res;
    }
};