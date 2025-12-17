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
    TreeNode* findNode(TreeNode* root, int x) {
        if (!root) {
            return NULL;
        }
        if (root->val == x) {
            return root;
        }

        TreeNode* got = findNode(root->left, x);
        if (got) {
            return got;
        }
        return findNode(root->right, x);
    }

    int level(TreeNode* root, TreeNode* target, int lvl) {
        if (!root) {
            return -1;
        }
        if (root == target) {
            return lvl;
        }

        int got = level(root->left, target, lvl + 1);
        if (got > -1) {
            return got;
        }
        return level(root->right, target, lvl + 1);
    }

    bool isSibling(TreeNode* root, TreeNode* x, TreeNode* y) {
        if (!root) {
            return false;
        }

        if ((root->left == x && root->right == y) ||
            (root->left == y && root->right == x)) {
            return true;
        }

        return isSibling(root->left, x, y) || isSibling(root->right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx = findNode(root, x);
        TreeNode* yy = findNode(root, y);

        return (level(root, xx, 0) == level(root, yy, 0)) &&
               (!isSibling(root, xx, yy));
    }
};