class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path = {0};

        function<void(int)> dfs = [&](int u) -> void {
            if (u == n - 1) {
                res.push_back(path);
                return;
            }

            for (auto& v : graph[u]) {
                path.push_back(v);
                dfs(v);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};