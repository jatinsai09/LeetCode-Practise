class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    ll modExp(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp & 1) {
                res = (res * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> vis(n + 1, false);
        int maxDepth = 0;

        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
            int sz = q.size(), f = 0;

            while (sz--) {
                int node = q.front();
                q.pop();

                for (auto &nbr : adj[node]) {
                    if (!vis[nbr]) {
                        f = 1;
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            maxDepth += f;
        }

        return (int)modExp(2LL, maxDepth - 1);
    }
};