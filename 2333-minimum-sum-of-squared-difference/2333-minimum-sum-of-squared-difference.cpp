class Solution {
#define ll long long int
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll n = nums1.size(), k = k1 + k2;

        ll mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, 1LL * abs(nums1[i] - nums2[i]));
        }

        ll l = 0, r = mx, m;
        while (l <= r) {
            m = l + (r - l) / 2;

            ll req = 0;
            for (int i = 0; i < n; i++) {
                ll d = abs(nums1[i] - nums2[i]);

                req += max(0LL, d - m);
            }

            if (req <= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        ll rem = k;
        for (int i = 0; i < n; i++) {
            ll d = abs(nums1[i] - nums2[i]);

            if (d > l) {
                rem -= (d - l);
            }
        } 
        
        ll res = 0;
        for (int i = 0; i < n; i++) {
            ll d = abs(nums1[i] - nums2[i]);
            d = min(d, l);

            if (d && d == l && rem) {
                d--;
                rem--;
            }

            res += d * d;
        }

        return res;
    }
};