class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) {
                    continue;
                }

                int got = 0;
                for (int i = 0; i < n; i++) {
                    int r = nums[i] % k;
                    if (i & 1) {
                        got += min((r - y + k) % k, (y - r + k) % k);
                    } else {
                        got += min((r - x + k) % k, (x - r + k) % k);
                    }
                }

                res = min(res, got);
            }
        }

        return res;
    }
};