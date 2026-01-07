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
    const int mod = 1e9 + 7;
    long long res = INT_MIN, total = 0;
    int dfs(TreeNode* root, bool compute){
        if (!root) return 0;
        
        int sum = root->val
            + dfs(root->left, compute)
            + dfs(root->right, compute);
        
        if (compute) res = max(res, (total - sum) * sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        total = dfs(root, 0);
        dfs(root, 1);
        
        return res % mod;
    }
};