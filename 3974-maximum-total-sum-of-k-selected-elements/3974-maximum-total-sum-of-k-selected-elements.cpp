class Solution {
#define ll long long
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(rbegin(nums), rend(nums));

        ll res = 0;
        for (int i = 0; i < k; i++) {
            if (mul > 1) {
                res += 1LL * nums[i] * mul--;
            } else {
                res += nums[i];
            }
        }

        return res;
    }
};