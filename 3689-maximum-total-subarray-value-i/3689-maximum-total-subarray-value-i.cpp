class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        return 1LL * (nums[n - 1] - nums[0]) * k;
    }
};