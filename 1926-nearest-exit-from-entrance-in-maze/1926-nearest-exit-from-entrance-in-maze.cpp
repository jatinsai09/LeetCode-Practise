class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n));

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        vector<int> dir = {1, 0, -1, 0, 1};
        int moves = 1;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i], nc = c + dir[i + 1];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        continue;
                    }

                    if (vis[nr][nc] || maze[nr][nc] == '+') {
                        continue;
                    }

                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        return moves;
                    }

                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
            moves++;
        }

        return -1;
    }
};