class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));

        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> v;

        function<void(int)> f = [&](int i) -> void {
            if (target == 0) {
                res.push_back(v);
                return;
            }

            if (i == n || target < 0) {
                return;
            }

            if (i && candidates[i - 1] == candidates[i]) {
                f(i + 1);
                return;
            }

            v.push_back(candidates[i]);
            target -= candidates[i];
            f(i);

            v.pop_back();
            target += candidates[i];
            f(i + 1);
        };

        f(0);
        return res;
    }
};