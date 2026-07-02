class Solution {
#define pii pair<int, int>
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mh(n, vector<int>(m, INT_MIN));

        deque<pii> dq;
        vector<int> dir = {1, 0, -1, 0, 1};
        mh[0][0] = health - grid[0][0];
        dq.push_back({0, 0});
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == n - 1 && c == m - 1) {
                return mh[n - 1][m - 1] >= 1;
            }

            int cur = mh[r][c];
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr < 0 || nc < 0|| nr >= n || nc >= m) {
                    continue;
                }

                int nxt = cur - grid[nr][nc];
                if (nxt > mh[nr][nc]) {
                    mh[nr][nc] = nxt;
                    if (grid[nr][nc]) {
                        dq.push_back({nr, nc});
                    } else {
                        dq.push_front({nr, nc});
                    }
                }
            }
        }
        return mh[n - 1][m - 1] >= 1;
    }
};