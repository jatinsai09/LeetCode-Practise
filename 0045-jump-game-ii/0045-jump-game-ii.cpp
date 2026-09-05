class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int p = 0, c = 0;
        while (p < n) {
            if (nums[p] + p >= n - 1) {
                return c + 1;
            }

            int mxi = 0, ind;
            for (int i = nums[p] + p; i > p; i--) {
                if (nums[i] + i > mxi) {
                    mxi = nums[i] + i;
                    ind = i;
                }
            }
            p = ind;
            c++;
        }

        return c;
    }
};