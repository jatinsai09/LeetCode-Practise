class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
    
        if (k == n) {
            int mx = nums[0];
            for (const auto& i : nums) {
                mx = max(i, mx);
            }
            return mx;
        }

        vector<int> f(52, 0);
        for (const auto& i : nums) {
            f[i]++;
        }

        int mx = -1;
        if (k == 1) {
            for (const auto &i: nums) {
                if (f[i] == 1) {
                    mx = max(mx, i);
                }
            }
        } else {
            if (f[nums[0]] == 1) {
                mx = max(mx, nums[0]);
            }
            if (f[nums[n - 1]] == 1) {
                mx = max(mx, nums[n - 1]);
            }
        }
        return mx;
    }
};