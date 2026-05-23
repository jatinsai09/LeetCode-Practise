class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), c0 = 0;
        for (auto &i: nums) {
            c0 += (i == 0);
        }

        int res = 0;
        for (int i = n - 1; i >= n - c0; i--) {
            res += (nums[i] != 0);
        }
        return res;
    }
};