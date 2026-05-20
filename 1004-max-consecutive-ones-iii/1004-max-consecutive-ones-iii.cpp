class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxlen = 0, c0 = 0;

        while (r < n) {
            if (!nums[r])
                c0++;

            if (c0 > k) {
                c0 -= (nums[l++] == 0);
            } else {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};