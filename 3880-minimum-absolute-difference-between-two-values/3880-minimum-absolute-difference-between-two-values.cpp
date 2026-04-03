class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size(), res = n;
        int p1 = -1, p2 = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (p2 != -1) {
                    res = min(res, i - p2);
                }
                p1 = i;
            } else if (nums[i] == 2) {
                if (p1 != -1) {
                    res = min(res, i - p1);
                }
                p2 = i;
            }
        }

        return (res == n ? -1 : res);
    }
};