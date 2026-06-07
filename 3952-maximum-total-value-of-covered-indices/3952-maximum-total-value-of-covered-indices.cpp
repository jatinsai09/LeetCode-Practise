class Solution {
#define ll long long int
public:
    long long maxTotal(vector<int>& nums, string s) {
        ll n = nums.size(), res = 0;

        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                prev = nums[i];
                continue;
            }

            int mn = nums[i], j = i;
            ll sum = 0;
            while (s[i] == s[j]) {
                mn = min(mn, nums[j]);
                sum += nums[j];
                j++;
            }

            res += sum;
            if (prev > mn) {
                res += prev - mn;
            }
            i = j - 1;
        }

        return res;
    }
};