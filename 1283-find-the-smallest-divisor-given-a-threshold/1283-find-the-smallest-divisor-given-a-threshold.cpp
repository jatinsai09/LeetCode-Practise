class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), mx = nums[0];
        for (const auto& i: nums) {
            mx = max(i, mx);
        }

        int l = 1, r = mx, m;
        while (l <= r) {
            m = (l + r) / 2;

            int got = 0;
            for (const auto& i: nums) {
                got += (i + m - 1) / m;
            }

            if (got > threshold) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};