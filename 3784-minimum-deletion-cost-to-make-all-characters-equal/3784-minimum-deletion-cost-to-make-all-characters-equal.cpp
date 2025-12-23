class Solution {
#define ll long long int    
public:
    long long minCost(string s, vector<int>& cost) {
        ll n = s.size(), sum = 0;
        vector<ll> t(26);

        for (int i = 0; i < n; i++) {
            t[s[i] - 'a'] += cost[i];
            sum += cost[i];
        }

        ll res = sum;
        for (int i = 0; i < 26; i++) {
            if (t[i]) {
                res = min(res, sum - t[i]);
            }
        }

        return res;
    }
};