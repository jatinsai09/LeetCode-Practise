class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> dir = {0, -1, 0, 1, 0};

        int r = grid.size(), c = grid[0].size();
        int vis[r][c];

        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int maxt = 0, rotten = 0;
        while (!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int t = p.second;
            maxt = max(t, maxt);

            for (int i = 0; i < 4; i++) {
                int dr = p.first.first + dir[i];
                int dc = p.first.second + dir[i + 1];

                if (dr >= 0 && dr < r && dc >= 0 && dc < c &&
                    vis[dr][dc] == 1) {
                    vis[dr][dc] = 2;
                    q.push({{dr, dc}, t + 1});
                    rotten++;
                }
            }
        }

        return (fresh == rotten ? maxt : -1);
    }
};