class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> adj(num);

        for (const auto& e: pre) {
            int v = e[0], u = e[1];

            adj[u].push_back(v);
        }

        int indegree[num];
        memset(indegree, 0, sizeof(indegree));
        for (int u = 0; u < num; u++) {
            for (const auto& v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < num; u++) {
            if (!indegree[u]) {
                q.push(u);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (const auto& v : adj[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (topo.size() == num) {
            return topo;
        }
        return {};
    }
};