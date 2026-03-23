class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), c0 = 0;
        long m = 1;
        for (const auto& i : nums) {
            if (i == 0) {
                c0++;
            } else {
                m *= i;
            }
        }

        vector<int> res(n, 0);
        if (c0 > 1) {
            return res;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                res[i] = (c0 ? 0 : m / nums[i]);
            } else {
                res[i] = m;
            }
        }

        return res;
    }
};