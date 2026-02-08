class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = 0, res = 0, n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            res += (nums[i] * (n - i - 1) > sum);
            sum += nums[i];
        }

        return res;
    }
};