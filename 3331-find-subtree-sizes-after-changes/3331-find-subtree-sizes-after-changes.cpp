class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n), adj2(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> prev(26, -1), np(n);
        np = parent;

        function<void(int, int)> dfs = [&](int u, int p) -> void {

            int og = prev[s[u] - 'a'];
            prev[s[u] - 'a'] = u;

            if (og != -1) {
                np[u] = og;
            }

            for (auto &v: adj[u]) {
                if (v == p) {
                    continue;
                }

                dfs(v, u);
            }

            prev[s[u] - 'a'] = og;

            if (u) adj2[np[u]].push_back(u);
        };
        dfs(0, -1);

        vector<int> res(n);

        function<int(int, int)> dfs2 = [&](int u, int p) -> int {

            int sz = 1;
            for (auto &v: adj2[u]) {
                if (v == p) {
                    continue;
                }

                sz += dfs2(v, u);
            }
        
            return res[u] = sz;
        };
        dfs2(0, -1);

        return res;
    }
};