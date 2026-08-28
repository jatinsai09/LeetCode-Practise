class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();

        vector<vector<int>> res = image;
        int iniColor = image[sr][sc];

        vector<int> dir = {1, 0, -1, 0, 1};

        function<void(int, int)> dfs = [&](int r, int c) -> void {
            res[r][c] = color;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }

                if (image[nr][nc] == iniColor && res[nr][nc] != color) {
                    dfs(nr, nc);
                }
            }
        };

        dfs(sr, sc);
        return res;
    }
};