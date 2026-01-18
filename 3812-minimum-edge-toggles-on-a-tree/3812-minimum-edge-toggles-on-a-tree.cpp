class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int> res, req(n);
        vector<vector<pair<int, int>>> adj(n + 1);
        int c = 0, par = 0;

        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
            c++;
        }

        for (int i = 0; i < n; i++) {
            req[i] = (start[i] != target[i]);
            par ^= (start[i] != target[i]);
        }

        if (par) {
            return {-1};
        }

        function<int(int, int)> dfs = [&](int u, int par) -> int {
            int flip = req[u];
            for (auto& it: adj[u]) {
                int v = it.first, ind = it.second;

                if (v == par) {
                    continue;
                }

                int child = dfs(v, u);
                if (child) {
                    res.push_back(ind);
                    flip = 1 - flip;
                }
            }
            return flip;
        };

        int got = dfs(0, -1);
        if (got) {
            return {-1};
        }

        sort(begin(res), end(res));
        return res;
    }
};