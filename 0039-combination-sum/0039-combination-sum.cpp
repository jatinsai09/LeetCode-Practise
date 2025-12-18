class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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

            f(i + 1);

            v.push_back(candidates[i]);
            target -= candidates[i];

            f(i);
            
            target += candidates[i];
            v.pop_back();
        };

        f(0);
        return res;
    }
};