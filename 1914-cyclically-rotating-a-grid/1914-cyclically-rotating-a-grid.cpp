class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> v;
            int top = l, left = l;
            int bottom = m - 1 - l, right = n - 1 - l;

            for (int j = left; j < right; j++) {
                v.push_back(grid[top][j]);
            }
            for (int i = top; i < bottom; i++) {
                v.push_back(grid[i][right]);
            }
            for (int j = right; j > left; j--) {
                v.push_back(grid[bottom][j]);
            }
            for (int i = bottom; i > top; i--) {
                v.push_back(grid[i][left]);
            }

            int len = v.size(), sft = k % len, idx = sft;

            for (int j = left; j < right; j++, idx++) {
                grid[top][j] = v[idx % len];
            }
            for (int i = top; i < bottom; i++, idx++) {
                grid[i][right] = v[idx % len];
            }
            for (int j = right; j > left; j--, idx++) {
                grid[bottom][j] = v[idx % len];
            }
            for (int i = bottom; i > top; i--, idx++) {
                grid[i][left] = v[idx % len];
            }
        }

        return grid;
    }
};