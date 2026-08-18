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

        if (k == 1) {
            int mx = -1;
            for (const auto &i: nums) {
                if (f[i] == 1) {
                    mx = max(mx, i);
                }
            }
            return mx;
        } else {
            if (f[nums[0]] == 1 and f[nums[n - 1]] == 1) {
                return max(nums[0], nums[n - 1]);
            } else if (f[nums[0]] == 1) {
                return nums[0];
            } else if (f[nums[n - 1]] == 1) {
                return nums[n - 1];
            }
        }
        return -1;
    }
};