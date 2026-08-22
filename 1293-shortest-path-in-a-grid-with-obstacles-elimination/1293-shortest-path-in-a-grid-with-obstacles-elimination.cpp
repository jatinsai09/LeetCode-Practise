class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        vector<int> dir = {1, 0, -1, 0, 1};
        queue<vector<int>> q;

        int steps = 0;
        q.push({0, 0, k});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto v = q.front();
                q.pop();

                int r = v[0], c = v[1], rem = v[2];
                
                if (r == n - 1 && c == m - 1) {
                    return steps;
                }

                if (grid[r][c] == 1) {
                    if (rem > 0) {
                        rem--;
                    } else {
                        continue;
                    }
                }

                if (vis[r][c] >= rem) {
                    continue;
                }
                vis[r][c] = rem;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i], nc = c + dir[i + 1];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                        continue;
                    } 

                    q.push({nr, nc, rem});
                }
            }
            steps++;
        }

        return -1;
    }
};