class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);

        for (const auto& p : pre) {
            adj[p[0]].push_back(p[1]);
        }

        vector<int> indegree(num);
        for (int u = 0; u < num; u++) {
            for (const auto& v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int v = 0; v < num; v++) {
            if (indegree[v] == 0) {
                q.push(v);
            }
        }

        int c = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            c++;

            for (const auto& v : adj[node]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return c == num;
    }
};