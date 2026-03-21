class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), c = 0;
        if (n <= 1) {
            return 0;
        }

        int p = 0;
        while (p < n) {
            if (nums[p] + p >= n - 1) {
                return c + 1;
            }

            int ms = 0, ind;
            for (int i = nums[p] + p; i > p; i--) {
                if (nums[i] + i > ms) {
                    ms = nums[i] + i;
                    ind = i;
                }
            }
            p = ind;
            c++;
        }

        return c;
    }
};