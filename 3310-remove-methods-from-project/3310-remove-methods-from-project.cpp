class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> res;

        vector<vector<int>> adj(n);
        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        vector<bool> visk(n), vis(n);

        queue<int> q;
        q.push(k);
        visk[k] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                if (!visk[v]) {
                    q.push(v);
                    visk[v] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] || visk[i]) {
                continue;
            }

            queue<int> q1;
            vis[i] = 1;
            q1.push(i);
            while (!q1.empty()) {
                int u = q1.front();
                q1.pop();

                for (auto& v : adj[u]) {
                    if (!vis[v]) {
                        q1.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }

        bool can = true;
        for (int i = 0; i < n; i++) {
            if (visk[i] && vis[i]) {
                can = false;
            }
        }

        if (!can) {
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
            return res;
        }

        for (int i = 0; i < n; i++) {
            if (!visk[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};