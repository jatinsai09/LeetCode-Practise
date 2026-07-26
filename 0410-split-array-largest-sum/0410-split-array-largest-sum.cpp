class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int mx = 0;
        long sum = 0;
        for (auto i : nums) {
            mx = max(i, mx);
            sum += i;
        }

        if (k == 1) {
            return (int)sum;
        }

        auto isValid = [&](long limit) {
            int cnt = 1;
            long sum = 0;
            for (const auto& i : nums) {
                sum += i;
                if (sum > limit) {
                    sum = i;
                    if (++cnt > k) {
                        return false;
                    }
                }
            }
            return true;
        };

        long mid, l = mx, r = sum;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isValid(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;
    }
};