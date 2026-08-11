class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int b = 0; b < 32; b++) {
            int c1 = 0;
            for (const auto &i: nums) {
                c1 += ((i >> b) & 1);
            }
            res += c1 * (n - c1);
        }
        return res;
    }
};