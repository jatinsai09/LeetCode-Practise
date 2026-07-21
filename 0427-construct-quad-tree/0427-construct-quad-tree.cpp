/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isUniform(auto& grid, int r, int c, int sz) {
        int key = grid[r][c];

        for (int i = r; i < r + sz; i++) {
            for (int j = c; j < c + sz; j++) {
                if (grid[i][j] != key) {
                    return false;
                }
            }
        }

        return true;
    }
    Node* build(auto& grid, int r, int c, int sz) {
        if (isUniform(grid, r, c, sz)) {
            return new Node(grid[r][c], true);
        }

        int hf = (sz >> 1);

        Node* root = new Node(1, false);

        root->topLeft = build(grid, r, c, hf);
        root->topRight = build(grid, r, c + hf, hf);
        root->bottomLeft = build(grid, r + hf, c, hf);
        root->bottomRight = build(grid, r + hf, c + hf, hf);

        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};