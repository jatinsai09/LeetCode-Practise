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
#define ll long long
public:
    int pathSum(TreeNode* root, int target) {
        unordered_map<ll, int> ps;
        ps[0] = 1;

        function<int(TreeNode*, ll)> dfs = [&](TreeNode* node, ll cur) -> int {
            if (!node) {
                return 0;
            }

            cur += node->val;
            int c = 0;
            if (ps.count(cur - target)) {
                c += ps[cur - target];
            }

            ps[cur]++;

            c += dfs(node->left, cur);
            c += dfs(node->right, cur);

            ps[cur]--;

            return c;
        };

        return dfs(root, 0); 
    }
};