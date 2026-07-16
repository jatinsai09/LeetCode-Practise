class Solution {
public:
    int n, m;
    vector<vector<int>> res;
    vector<vector<bool>> atlantic, pacific;
    queue<pair<int, int>> q;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = size(heights), m = size(heights[0]);
        atlantic = pacific = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            bfs(heights, pacific, i, 0);
            bfs(heights, atlantic, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            bfs(heights, pacific, 0, j);
            bfs(heights, atlantic, n - 1, j);
        }

        return res;
    }

    void bfs(auto& mat, auto& vis, int i, int j) {
        q.push({i, j});
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if(vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            if(atlantic[i][j] && pacific[i][j]) {
                res.push_back({i, j});
            }

            if(i + 1 <  n && mat[i + 1][j] >= mat[i][j]) q.push({i + 1, j});
            if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) q.push({i - 1, j});
            if(j + 1 <  m && mat[i][j + 1] >= mat[i][j]) q.push({i, j + 1});
            if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) q.push({i, j - 1});
        }
    }

};