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
#define ll long long int
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        ll sum = 0;

        function<ll(TreeNode*)> dfs = [&](TreeNode* root) -> ll {
            if (!root->left && !root->right) {
                return root->val;
            }
            sum += root->val;

            ll mx = INT_MIN;
            if (root->left) {
                ll l = dfs(root->left);
                if (l + sum < limit) {
                    root->left = NULL;
                }
                mx = max(mx, l);
            }
            
            if (root->right) {
                ll r = dfs(root->right);
                if (r + sum < limit) {
                    root->right = NULL;
                }
                mx = max(mx, r);
            }

            sum -= root->val;

            return mx + root->val;
        };

        ll mx = dfs(root);
        if (mx < limit) {
            return NULL;
        }

        return root;
    }
};