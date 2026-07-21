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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh = ht(root->left);
        int rh = ht(root->right);

        if (lh == rh) {
            return (1 << lh) + countNodes(root->right);
        } else {
            return (1 << rh) + countNodes(root->left);
        }
    }

    int ht(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
};