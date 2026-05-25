class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        sort(nums.begin(), nums.end());
        int c = 1, res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= 1) {
                c += (nums[i] - nums[i - 1]);
            } else {
                c = 1;
            }
            res = max(res, c);
        }
        return res;
    }
};