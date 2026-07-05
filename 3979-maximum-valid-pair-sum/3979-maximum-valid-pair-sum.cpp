class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, pmx = 0;

        for (int j = k; j < n; j++) {
            pmx = max(pmx, nums[j - k]);
            res = max(res, nums[j] + pmx);
        }   

        return res;
    }
};