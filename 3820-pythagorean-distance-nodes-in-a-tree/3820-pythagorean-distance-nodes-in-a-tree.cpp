class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto bfs = [&](int s) -> vector<long long> {
            vector<long long> dist(n, -1);
            queue<int> q;
            q.push(s);
            dist[s] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto &v: adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1LL;
                        q.push(v);
                    }
                }
            }

            return dist;
        };

        vector<long long> dx = bfs(x);
        vector<long long> dy = bfs(y);
        vector<long long> dz = bfs(z);

        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> a = {dx[i], dy[i], dz[i]};
            sort(begin(a), end(a));

            if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
                res++;
            }
        }

        return res;
    }
};