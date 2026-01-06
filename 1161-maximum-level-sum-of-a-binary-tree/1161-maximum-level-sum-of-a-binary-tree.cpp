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
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0, lvl_m = 0, maxi = INT_MIN;

        while (!q.empty()) {
            int sz = q.size(), sum = 0;
            lvl++;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            (sum > maxi ? (lvl_m = lvl, maxi = sum) : 1);
        }
        return lvl_m;
    }
};