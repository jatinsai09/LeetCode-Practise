class Solution {
#define ll long long int
public:
    long long countGoodSubarrays(vector<int>& nums) {
        ll n = nums.size(), res = 0;

        vector<ll> l(n, 0), r(n, n - 1);
        unordered_map<ll, ll> prev;

        vector<ll> last(30, -1), next(30, n);
        for (int i = 0; i < n; i++) {
            ll lb = 0;

            if (prev.count(nums[i])) {
                lb = max(lb, prev[nums[i]] + 1);
            }

            for (int b = 0; b < 30; b++) {
                if ((nums[i] >> b) & 1) {
                    continue;
                } 

                lb = max(lb, last[b] + 1);
            }
            l[i] = lb;

            prev[nums[i]] = i;
            for (int b = 0; b < 30; b++) {
                if ((nums[i] >> b) & 1) {
                    last[b] = i;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            ll rb = n - 1;

            for (int b = 0; b < 30; b++) {
                if ((nums[i] >> b) & 1) {
                    continue;
                } 
                rb = min(rb, next[b] - 1);
            }
            r[i] = rb;

            for (int b = 0; b < 30; b++) {
                if ((nums[i] >> b) & 1) {
                    next[b] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ll lc = i - l[i] + 1, rc = r[i] - i + 1;

            res += lc * rc;
        }

        return res;
    }
};