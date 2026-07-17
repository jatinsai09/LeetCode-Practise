class Solution {
#define ll long long int
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();

        int mx = nums[0];
        for (auto &i: nums) {
            mx = max(mx, i);
        }

        vector<ll> f(mx + 1), gc(f);
        for (auto &i: nums) {
            f[i]++;
        }

        for (int i = mx; i >= 1; i--) {
            ll c = 0, got = 0;
            for (int j = i; j <= mx; j += i) {
                c += f[j];
                got -= gc[j];
            }
            got += c * (c - 1) / 2;
            
            gc[i] = got;
        }
        vector<ll> pgc(mx + 1);
        for (int i = 1; i <= mx; i++) {
            pgc[i] = gc[i] + pgc[i - 1];
        }

        vector<int> res;
        for (auto& q: queries) {
            int g = lower_bound(begin(pgc), end(pgc), q + 1) - begin(pgc);

            res.push_back(g);
        }

        return res;
    }
};