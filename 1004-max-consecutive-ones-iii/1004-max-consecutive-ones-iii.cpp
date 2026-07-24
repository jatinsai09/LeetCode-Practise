class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0, c0 = 0;

        for (int l = 0, r = 0; r < n; r++) {
            c0 += (nums[r] == 0);

            if (c0 > k) {
                c0 -= (nums[l++] == 0);
            } else {
                maxlen = max(maxlen, r - l + 1);
            }
        }
        return maxlen;
    }
};