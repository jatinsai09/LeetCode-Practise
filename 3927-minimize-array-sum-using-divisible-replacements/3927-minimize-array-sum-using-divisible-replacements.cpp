class Solution {
#define ll long long int
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<int, int> f;
        int n = nums.size();

        for (auto &i: nums) {
            f[i]++;
        }

        ll res = 0;
        for (auto &i: nums) {
            ll val = i;
            for (ll d = 1; d * d <= i; d++) {
                if (i % d == 0) {
                    if (f[d]) {
                        val = min(val, d);
                    } 
                    if (f[i / d]) {
                        val = min(val, i / d);
                    }
                }
            }
            res += val;
        }
        return res;
    }
};