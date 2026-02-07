class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n);

        for (auto &e: richer) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            deg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res(n);
        iota(begin(res), end(res), 0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v: adj[u]) {
                if (quiet[res[v]] > quiet[res[u]]) {
                    res[v] = res[u];
                }
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return res;
    }
};