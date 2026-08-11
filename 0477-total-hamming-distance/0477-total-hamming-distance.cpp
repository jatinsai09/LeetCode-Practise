class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int b = 0; b < 32; b++) {
            int c1 = 0, c0 = 0;
            for (const auto &i: nums) {
                if ((i >> b) & 1) {
                    c0++;
                } else {
                    c1++;
                }
            }
            res += c1 * c0;
        }
        return res;
    }
};