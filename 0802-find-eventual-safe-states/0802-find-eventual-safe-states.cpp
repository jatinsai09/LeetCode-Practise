class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int v = adj.size();
        vector<vector<int>> adjRev(v);
        int indegree[v];
        memset(indegree, 0, sizeof(indegree));
        for (int i = 0; i < v; i++) {
            // i->it;
            // it->i;
            for (auto& it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);
            for (auto& it : adjRev[node]) {
                if (--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(begin(safe), end(safe));
        return safe;
    }
};