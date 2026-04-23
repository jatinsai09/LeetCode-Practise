class Solution {
#define ll long long int
public:
    vector<long long> distance(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> res(n);

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [k, pos] : mp) {
            ll t = 0;
            for (auto& i : pos) {
                t += i;
            }

            ll ls = 0;
            int m = pos.size();
            for (ll i = 0; i < m; i++) {
                ll rs = t - ls - pos[i];

                ll l = pos[i] * i - ls;
                ll r = rs - pos[i] * (m - i - 1);

                res[pos[i]] = l + r;

                ls += pos[i];
            }
        }

        return res;
    }
};