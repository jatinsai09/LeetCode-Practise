class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> adj(num);

        for (int i = 0; i < pre.size(); i++) {
            int first = pre[i][0];
            int second = pre[i][1];

            adj[second].push_back(first);
        }

        int indegree[num];
        memset(indegree, 0, sizeof(indegree));
        for (int i = 0; i < num; i++) {
            for (auto& it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto& it : adj[node]) {
                if (--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (topo.size() == num) {
            return topo;
        }
        return {};
    }
};