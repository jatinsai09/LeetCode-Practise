class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), q = queries.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> res(n, -1);
        for (auto& p : mp) {
            auto v = p.second;
            int m = v.size();
            if (m > 1) {
                for (int i = 0; i < m; i++) {
                    int f = v[(i + 1) % m], b = v[(i - 1 + m) % m];
                    int fd = min(abs(v[i] - f), n - abs(v[i] - f));
                    int bd = min(abs(v[i] - b), n - abs(v[i] - b));
                    res[v[i]] = min(bd, fd);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            queries[i] = res[queries[i]];
        }
        return queries;
    }
};