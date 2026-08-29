class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e: redEdges) {
            adj[e[0]].push_back({e[1], 0});
        }
        for (auto &e: blueEdges) {
            adj[e[0]].push_back({e[1], 1});
        }

        vector<int> res(n, -1);
        res[0] = 0;

        vector<vector<bool>> vis(n, vector<bool>(2));
        queue<pair<int, int>> q;

        q.push({0, 0});
        q.push({0, 1});
        vis[0][0] = vis[0][1] = true;

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [u, prev] = q.front();
                q.pop();

                if (res[u] == -1) {
                    res[u] = dist;
                }

                for (auto &[v, clr]: adj[u]) {
                    if (clr != prev && !vis[v][clr]) {
                        vis[v][clr] = true;
                        q.push({v, clr});
                    }
                }
            }
            dist++;
        }

        return res;
    }
};