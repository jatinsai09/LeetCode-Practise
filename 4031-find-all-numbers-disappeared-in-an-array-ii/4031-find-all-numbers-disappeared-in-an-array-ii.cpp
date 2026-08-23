class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        vector<vector<int>> res;

        int st = lower;
        for (int i = 0; i < n; i++) {
            if (nums[i] < lower || nums[i] > upper) {
                continue;
            }

            if (nums[i] > st) {
                res.push_back({st, nums[i] - 1});
            }
            st = nums[i] + 1;
        }

        if (st <= upper) {
            res.push_back({st, upper});
        }

        return res;
    }
};