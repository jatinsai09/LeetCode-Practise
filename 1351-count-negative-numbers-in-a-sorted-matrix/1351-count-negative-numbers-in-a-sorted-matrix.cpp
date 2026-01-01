class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int c = 0, j = m;
        for (int i = 0; i < n; i++) {
            while (j && grid[i][j - 1] < 0) {
                j--;
            }
            c += m - j;
        }
        return c;
    }
};