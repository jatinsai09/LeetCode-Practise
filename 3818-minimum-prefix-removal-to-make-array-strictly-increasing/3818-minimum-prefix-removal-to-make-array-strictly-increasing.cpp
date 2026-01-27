class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                res = i;
            }
        }
        return res;
    }
};