class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int n = nums.size(), res = nums[n - 1] - nums[0];

        for (int i = 0; i + 1 < n; i++) {
            int mn = min(nums[0] + k, nums[i + 1] - k);
            int mx = max(nums[i] + k, nums[n - 1] - k);

            res = min(res, mx - mn);
        }

        return res;
    }
};