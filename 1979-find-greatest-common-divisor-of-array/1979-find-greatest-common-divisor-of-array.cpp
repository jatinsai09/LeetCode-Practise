class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (const auto& i: nums) {
            mn = min(i, mn);
            mx = max(i, mx);
        }

        return gcd(mx, mn);
    }
};