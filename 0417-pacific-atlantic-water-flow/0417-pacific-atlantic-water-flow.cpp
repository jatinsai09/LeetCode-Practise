class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m)), atlantic(pacific), res;
        
        int dir[] = {1, 0, -1, 0, 1};
        function<void(vector<vector<int>>&, int, int)> bfs = [&](auto& vis, int si, int sj) -> void {
            queue<pair<int, int>> q;
            q.push({si, sj});

            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                if (vis[i][j]) {
                    continue;
                }
                vis[i][j] = 1;

                if(atlantic[i][j] && pacific[i][j]) {
                    res.push_back({i, j});
                } 

                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k], nj = j + dir[k + 1];

                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                        continue;
                    }

                    if (heights[ni][nj] >= heights[i][j]) {
                        q.push({ni, nj});
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            bfs(pacific, i, 0);
            bfs(atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            bfs(pacific, 0, j);
            bfs(atlantic, n - 1, j);
        }

        return res;
    }
};