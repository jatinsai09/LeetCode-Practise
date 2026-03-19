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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> build = [&](int is, int ie,
                                                            int ps, int pe) -> TreeNode* {
            if (is > ie) {
                return NULL;
            }

            TreeNode* root = new TreeNode(postorder[pe]);
            int ind = mp[postorder[pe]];

            int ls = ind - is;
            root->left = build(is, ind - 1, ps, ps + ls - 1);
            root->right = build(ind + 1, ie, ps + ls, pe - 1);

            return root;
        };

        return build(0, n - 1, 0, n - 1);
    }
};