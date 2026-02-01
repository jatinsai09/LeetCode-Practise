class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        auto cmp = [&](int a, int b) {
            if (a == b) {
                return 0;
            }

            return (a > b ? 1 : -1);
        };
        
        int res = 1;
        vector<int> l(n, 1);
        for (int i = 1; i < n; i++) {
            int d = cmp(nums[i], nums[i - 1]);
            if (d == 0) {
                continue;
            }

            if (i - 2 >= 0 && cmp(nums[i - 1], nums[i - 2]) == -d) {
                l[i] = l[i - 1] + 1;
            } else {
                l[i] = 2;
            }
            res = max(res, l[i]);
        }

        vector<int> r(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            int d = cmp(nums[i + 1], nums[i]);
            if (d == 0) {
                continue;
            }

            if (i + 2 < n && cmp(nums[i + 2], nums[i + 1]) == -d) {
                r[i] = r[i + 1] + 1;
            } else {
                r[i] = 2;
            }
        }

        for (int i = 1; i + 1 < n; i++) {
            int d = cmp(nums[i + 1], nums[i - 1]);
            if (d == 0) {
                continue;
            }

            int L = (i > 1 && cmp(nums[i - 1], nums[i - 2]) == -d) ? l[i - 1] : 1;
            int R = (i + 2 < n && cmp(nums[i + 2], nums[i + 1]) == -d) ? r[i + 1] : 1;

            res = max(res, L + R);
        }

        return res;
    }
};