class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> vis(n + 1);

        vector<int> res;
        function<bool(int)> dfs = [&](int u) -> bool {
            if (vis[u] == 1) {
                return false;
            }

            if (vis[u] == 2) {
                return true;
            }

            vis[u] = 1;
            for (auto &v: adj[u]) {
                if (!dfs(v)) {
                    return false;
                }
            }
            vis[u] = 2;

            return true;
        };

        for (int i = 0; i < n; i++) {
            if (dfs(i)) {
                res.push_back(i);
            }
        }

        return res;
    }
};