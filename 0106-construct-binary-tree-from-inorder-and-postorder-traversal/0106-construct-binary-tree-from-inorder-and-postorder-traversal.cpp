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
        int n = inorder.size(), postIdx = n - 1;
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1, postIdx, mp);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd,
                    int& postIdx, unordered_map<int, int> mp) {
        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(post[postIdx--]);

        int inIdx = mp[root->val];

        root->right = build(in, post, inIdx + 1, inEnd, postIdx, mp);
        root->left = build(in, post, inStart, inIdx - 1, postIdx, mp);

        return root;
    }
};