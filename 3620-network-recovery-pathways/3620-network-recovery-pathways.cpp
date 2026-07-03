class Solution {
#define ll long long
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {

        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
        }

        int l = 0, r = 1e9, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;

            vector<ll> dp(n, LLONG_MAX);
            vector<int> indegree(n, 0);
            vector<vector<pair<int, int>>> graph(n);

            for (int u = 0; u < n; u++) {
                for (auto& [v, cost] : adj[u]) {
                    if (cost >= mid && online[v]) {
                        graph[u].push_back({v, cost});
                        indegree[v]++;
                    }
                }
            }

            {
                queue<int> q;
                dp[0] = 0;
                for (int i = 0; i < n; i++) {
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (auto& [v, cost] : graph[u]) {
                        if (dp[u] != LLONG_MAX && dp[u] + cost < dp[v]) {
                            dp[v] = dp[u] + cost;
                        }
                        if (--indegree[v] == 0) {
                            q.push(v);
                        }
                    }
                }
            }

            if (dp[n - 1] <= k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
};