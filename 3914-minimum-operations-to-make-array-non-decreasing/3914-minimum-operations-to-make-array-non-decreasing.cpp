class Solution {
#define ll long long
public:
    long long minOperations(vector<int>& nums) {
        ll n = nums.size(), res = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                res += nums[i - 1] - nums[i];
            }
        }
        return res;
    }
};