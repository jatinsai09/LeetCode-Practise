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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int, int> inMap;

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> f = [&](int preStart, int preEnd, int inStart, int inEnd) -> TreeNode* {
            if (inStart > inEnd) {
                return NULL;
            }

            TreeNode* root = new TreeNode(preorder[preStart]);

            int inRoot = inMap[root->val];
            int numsLeft = inRoot - inStart;

            root->left = f(preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
            root->right = f(preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);

            return root;
        };

        return f(0, n - 1, 0, n - 1);
    }
};