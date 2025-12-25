class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size(), cols = mat[0].size();
        int r = rows - 1, c = 0;
        
        while (r >= 0 && c < cols) {
            if (mat[r][c] == target) {
                return true;
            } else if (mat[r][c] > target) {
                r--;
            } else {
                c++;
            }
        }
        return false;
    }
};