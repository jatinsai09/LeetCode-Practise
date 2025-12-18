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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* prevNode = nullptr;
        int mxc = 0, cur = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) -> void {
            if (!node) {
                return;
            }

            inorder(node->left);

            if (!prevNode || node->val != prevNode->val) {
                cur = 1;
            } else {
                cur++;
            }

            if (cur > mxc) {
                mxc = cur;
                res.clear();
                res.push_back(node->val);
            } else if (cur == mxc) {
                res.push_back(node->val);
            }

            prevNode = node;
            inorder(node->right);
        };

        inorder(root);
        return res;   
    }
};