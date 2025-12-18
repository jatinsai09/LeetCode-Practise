class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        int color = 0;

        function<bool(int, int)> dfs = [&](int u, int color) -> bool {
            vis[u] = color;
            
            for (const auto& v: graph[u]) {
                if (vis[v] == -1) {
                    if (!dfs(v, !color)) {
                        return false;
                    }
                } else {
                    if (vis[v] == color) {
                        return false;
                    }
                }
            }

            return true;
        };

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};