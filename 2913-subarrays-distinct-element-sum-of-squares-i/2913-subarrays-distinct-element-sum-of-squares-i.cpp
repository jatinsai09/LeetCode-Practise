class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            int f[101] = {0}, d = 0;
            for (int j = i; j < n; j++) {
                if (++f[nums[j]] == 1) {
                    d++;
                }
                res += d * d;
            }
        }
        return res;
    }
};