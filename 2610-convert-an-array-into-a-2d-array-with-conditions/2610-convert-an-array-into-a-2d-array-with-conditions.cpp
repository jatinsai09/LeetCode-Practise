class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n + 1);

        int mf = 0;
        for (auto &i: nums) {
            f[i]++;
            mf = max(mf, f[i]);
        }

        vector<vector<int>> res(mf);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < f[i]; j++) {
                res[j].push_back(i);
            }
        }

        return res;
    }
};