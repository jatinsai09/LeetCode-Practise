class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = score.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        function<int(int)> dfs = [&](int u) -> int {
            if (adj[u].empty()) {
                return score[u];
            }

            int t = score[u], mn = INT_MAX;
            for (auto &v: adj[u]) {
                int got = dfs(v);
                mn = min(mn, got);
                t += got;
            }

            if (op[u] || mn < 0) {
                t -= mn;
            }

            return t;
        };

        return dfs(0);
    }
};