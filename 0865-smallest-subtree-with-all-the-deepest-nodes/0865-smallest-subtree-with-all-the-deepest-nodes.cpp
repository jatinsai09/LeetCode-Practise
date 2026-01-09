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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }

    pair<int, TreeNode*> depth(TreeNode* root) {
        if (!root) {
            return {0, NULL};
        }

        auto l = depth(root->left), r = depth(root->right);
        int dl = l.first, dr = r.first;

        if (dl == dr) {
            return {dl + 1, root};
        } else if (dl > dr) {
            return {dl + 1, l.second};
        } else {
            return {dr + 1, r.second};
        }
    }
};