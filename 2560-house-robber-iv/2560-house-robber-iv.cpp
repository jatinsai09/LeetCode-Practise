class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mn = nums[0], mx = nums[0];
        for (const auto &i: nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }

        int n = nums.size(), l = mn, r = mx, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int got = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    got++;
                    i++;
                }
            }
            if (got >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};