class Solution {
#define ll long long int
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for (auto &e: edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
        }

        function<ll(ll)> dfs = [&](ll u) -> ll {
            ll latest = LLONG_MIN, earliest = LLONG_MAX;

            for (auto &v: adj[u]) {
                ll fin = dfs(v);

                latest = max(latest, fin);
                earliest = min(earliest, fin);
            }

            if (latest == LLONG_MIN) {
                return baseTime[u];
            }

            return latest + (latest - earliest) + baseTime[u];
        };

        return dfs(0);
    }
};