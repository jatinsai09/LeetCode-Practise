class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), total = 0;
        for (const auto &i: nums) {
            total += i;
        }

        if (x > total) {
            return -1;
        }

        int res = -1, cur = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cur += nums[r];

            while (cur > total - x) {
                cur -= nums[l++];
            }

            if (cur == total - x) {
                res = max(res, r - l + 1);
            }
        }
        
        return (res == -1 ? -1 : n - res);
    }
};