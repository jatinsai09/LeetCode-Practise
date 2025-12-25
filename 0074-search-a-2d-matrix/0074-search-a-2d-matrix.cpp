class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size(), cols = mat[0].size();
        int r = 0, c = cols - 1;

        while (r < rows && c >= 0) {
            int cur = mat[r][c];
            if (cur == target) {
                return true;
            }
            if (target > cur) {
                r++;
            }
            else {
                c--;
            }
        }
        return false;
    }
};