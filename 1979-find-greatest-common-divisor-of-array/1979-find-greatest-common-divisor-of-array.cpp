class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size(), mn = nums[0], mx = nums[0];

        for (int i = 1; i < n; i++) {
            mn = min(nums[i], mn);
            mx = max(nums[i], mx);
        }

        return gcd(mx, mn);
    }
};