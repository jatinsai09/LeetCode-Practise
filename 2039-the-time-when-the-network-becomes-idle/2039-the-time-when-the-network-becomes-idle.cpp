class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);

        for (const auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n, -1);
        queue<int> q;
        
        time[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int u = q.front();
                q.pop();

                for (const auto& v: adj[u]) {
                    if (time[v] == -1) {
                        time[v] = 1 + time[u];
                        q.push(v);
                    }
                }
            }
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            int tt = time[i] * 2;

            int k = (tt - 1) / patience[i]; 

            res = max(res, k * patience[i] + tt);
        }

        return res + 1;
    }
};