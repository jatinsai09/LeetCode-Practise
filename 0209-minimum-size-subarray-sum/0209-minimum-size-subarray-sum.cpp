class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, cur = 0;

        for (int l = 0, r = 0; r < n; r++) {
            cur += nums[r];

            while (cur >= target) {
                if (r - l + 1 < mn) {
                    mn = r - l + 1;
                }
                cur -= nums[l++];
            }
        }

        return mn == INT_MAX ? 0 : mn;
    }
};