class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> f(50), res(n - k + 1);

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                f[nums[i] + 50]++;
            }
            if (i - k >= 0 && nums[i - k] < 0) {
                f[nums[i - k] + 50]--;
            }

            if (i + 1 >= k) {
                int c = 0;
                for (int j = 0; j < 50; j++) {
                    c += f[j];
                    if (c >= x) {
                        res[i - k + 1] = j - 50;
                        break;
                    }
                }
            }
        }

        return res;
    }
};