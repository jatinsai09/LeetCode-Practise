/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        string s = "";
        s = to_string(root->val) + "(" + serialize(root->left) + ")" + "(" +
            serialize(root->right) + ")";

        return s;
    }

    TreeNode* decode(string& data, int& i) {
        if (data[i] == '(') {
            i++;
        }
        if (i >= data.size() || data[i] == ')') {
            return NULL;
        }

        int sign = 1;
        if (data[i] == '-') {
            sign = -1;
            i++;
        }

        int val = 0;
        while (i < data.size() && data[i] >= '0' && data[i] <= '9') {
            val = val * 10 + (data[i] - '0');
            i++;
        }
        val *= sign;

        TreeNode* root = new TreeNode(val);

        root->left = decode(data, i);
        i++;

        root->right = decode(data, i);
        i++;

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;

        return decode(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));