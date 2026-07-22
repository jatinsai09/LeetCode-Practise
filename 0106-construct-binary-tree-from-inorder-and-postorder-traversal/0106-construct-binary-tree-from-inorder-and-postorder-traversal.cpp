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

        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> build = [&](int postStart, int postEnd,
                                                            int inStart, 
                                                            int inEnd) -> TreeNode* {
            if (inStart > inEnd) {
                return NULL;
            }

            TreeNode* root = new TreeNode(postorder[postEnd]);
            
            int inRoot = inMap[root->val];
            int numsLeft = inRoot - inStart;

            root->left = build(postStart, postStart + numsLeft - 1, inStart, inRoot - 1);
            root->right = build(postStart + numsLeft, postEnd - 1, inRoot + 1, inEnd);

            return root;
        };

        return build(0, n - 1, 0, n - 1);
    }
};