class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;

        function<void(int)> dfs = [&](int u) -> void {
            if (u == n - 1) {
                path.push_back(u);
                res.push_back(path);
                path.pop_back();
                return;
            }

            path.push_back(u);
            for (auto& v : graph[u]) {
                dfs(v);
            }
            path.pop_back();
        };

        dfs(0);
        return res;
    }
};