class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            int e = 0, o = 0;
            for (int j = i; j < n; j++) {
                (nums[j] & 1 ? o++ : e++);

                if (o > 0) {
                    res += (1LL * e * b <= 1LL * a * o);
                }
            }
        }
        return res;
    }
};