class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        function<void(int, vector<int>)> f = [&](int ind, auto a) {
            if (ind == n) {
                res.push_back(a);
                return;
            }

            for (int i = ind; i < n; i++) {
                swap(a[i], a[ind]);
                f(ind + 1, a);
            }
        };

        f(0, nums);

        return res;
    }
};