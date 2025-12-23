class Solution {
#define ll long long int
public:
    long long interactionCosts(int n, vector<vector<int>>& edges,
                               vector<int>& group) {
        ll res = 0;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<ll> t(21);
        for (auto& i : group) {
            t[i]++;
        }

        vector<vector<ll>> f(n, vector<ll>(21));

        function<void(int, int)> dfs = [&](int u, int p) -> void {
            f[u][group[u]]++;

            for (auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }

                dfs(v, u);

                for (int g = 1; g <= 20; g++) {
                    if (f[v][g]) {
                        res += f[v][g] * (t[g] - f[v][g]);
                    }
                    f[u][g] += f[v][g];
                }
            }
        };

        dfs(0, -1);
        return res;
    }
};