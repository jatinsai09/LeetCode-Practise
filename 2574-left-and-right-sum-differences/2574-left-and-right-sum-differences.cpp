class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int lsum = 0, rsum = 0;
        for (auto &i: nums) {
            rsum += i;
        }

        for (int i = 0; i < n; i++) {
            rsum -= nums[i];
            res[i] = abs(lsum - rsum);
            lsum += nums[i];
        }
        return res;
    }
};