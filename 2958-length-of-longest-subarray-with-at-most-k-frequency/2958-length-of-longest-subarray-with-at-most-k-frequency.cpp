class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> mp;

        for (int l = 0, r = 0; r < n; r++) {
            ++mp[nums[r]];

            while (mp[nums[r]] > k) {
                --mp[nums[l++]];
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};