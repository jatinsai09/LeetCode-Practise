class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));

        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> v;

        function<void(int)> f = [&](int i) -> void {
            if (target == 0) {
                res.push_back(v);
                return;
            }

            for (int ind = i; ind < n; ind++) {
                if (ind > i && candidates[ind] == candidates[ind - 1]) {
                    continue;
                }

                if (candidates[i] > target) {
                    return;
                }

                target -= candidates[ind];
                v.push_back(candidates[ind]);

                f(ind + 1);

                target += candidates[ind];
                v.pop_back();
            }
        };

        f(0);
        return res;
    }
};