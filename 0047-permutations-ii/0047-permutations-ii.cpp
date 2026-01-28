class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> res;

        function<void(int, vector<int>)> f = [&](int i, auto nums) -> void {
            if (i == n - 1) {
                res.push_back(nums);
                return;
            }

            for (int j = i; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    continue;
                }
                swap(nums[i], nums[j]);
                f(i + 1, nums);
            }
        };

        f(0, nums);
        return res;
    }

};