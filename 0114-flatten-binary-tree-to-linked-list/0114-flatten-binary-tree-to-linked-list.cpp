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
    void pre(TreeNode * root, TreeNode * &par) {
        if (!root) {
            return;
        } 

        par->right = root;
        par->left = NULL;

        TreeNode *l = root->left, *r = root->right;
        par = root;
        
        pre(l, par);
        pre(r, par);
    }
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        TreeNode *dummy = new TreeNode(-1);
        TreeNode *par = dummy;
        pre(root, par);

        root=dummy->right;
    }
};