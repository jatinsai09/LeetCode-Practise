class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int res = 1, prev = nums[0], c = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - prev <= 1) {
                c += nums[i] - prev;
            } else {
                c = 1;
            }
            res = max(res, c);
            prev = nums[i];
        }
        return res;
    }
};