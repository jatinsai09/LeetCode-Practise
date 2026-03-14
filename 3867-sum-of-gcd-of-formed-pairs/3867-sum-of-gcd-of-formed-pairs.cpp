class Solution {
#define ll long long int
public:
    long long gcdSum(vector<int>& nums) {
        ll n = nums.size(), mx = 0;

        vector<int> pg(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, (ll)nums[i]);
            pg[i] = gcd(mx, nums[i]);
        }
        sort(begin(pg), end(pg));

        ll sum = 0, l = 0, r = n - 1;
        while (l < r) {
            sum += gcd(pg[l++], pg[r--]);
        }

        return sum;
    }
};