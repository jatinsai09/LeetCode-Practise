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
    TreeNode* invertTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (!root) {
            return nullptr;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            TreeNode* temp = top->left;
            top->left = top->right;
            top->right = temp;

            if (top->left) {
                q.push(top->left);
            }
            if (top->right) {
                q.push(top->right);
            }
        }
        return root;
    }
};