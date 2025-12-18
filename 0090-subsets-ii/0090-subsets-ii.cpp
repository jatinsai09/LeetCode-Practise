class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;
        vector<int> v;
        sort(begin(nums), end(nums));

        function<void(int)> f = [&](int i) -> void {
            res.push_back(v);

            for (int j = i; j < n; j++) {
                if (j > i && nums[j] == nums[j - 1]) {
                    continue;
                }

                v.push_back(nums[j]);
                f(j + 1);
                v.pop_back();
            }
        };

        f(0);
        return res;
    }
};