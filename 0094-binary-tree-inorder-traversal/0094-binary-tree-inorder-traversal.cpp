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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        //inorder(root,res);

        TreeNode* cur = root;

        while (cur) {
            if (cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right; 
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = cur;

                    cur = cur->left;
                } else {
                    res.push_back(cur->val);

                    pred->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return res;
    }

    void inorder(TreeNode* node,vector<int>& res){
        if(!node) return;

        inorder(node->left,res);
        res.push_back(node->val);
        inorder(node->right,res);
    }
};