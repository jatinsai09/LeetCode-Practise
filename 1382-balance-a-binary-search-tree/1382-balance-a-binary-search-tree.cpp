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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return build_balanced(sorted, 0, sorted.size() - 1);
    }
    void inorder(TreeNode* node, vector<int>& sorted) {
        if (!node) {
            return;
        }
        inorder(node->left, sorted);
        sorted.push_back(node->val);
        inorder(node->right, sorted);
    }

    TreeNode* build_balanced(vector<int>& sorted, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(sorted[mid]);

        node->left = build_balanced(sorted, start, mid - 1);
        node->right = build_balanced(sorted, mid + 1, end);
        
        return node;
    }
};