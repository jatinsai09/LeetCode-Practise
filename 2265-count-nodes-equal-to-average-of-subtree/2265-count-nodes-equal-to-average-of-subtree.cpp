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
#define pii pair<int, int>
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;

        function<pii(TreeNode*)> dfs = [&](TreeNode* root) -> pii {
            if (!root) {
                return {0, 0};
            }

            int c = 1, sum = root->val;
            
            auto l = dfs(root->left);
            auto r = dfs(root->right);

            c += l.first + r.first;
            sum += l.second + r.second;

            res += (root->val == (sum / c));

            return {c, sum};
        };
        dfs(root);
        
        return res;
    }
};