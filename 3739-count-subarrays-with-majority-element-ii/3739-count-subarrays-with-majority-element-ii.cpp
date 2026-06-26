class Solution {
#define ll long long    
public:
    long long countMajoritySubarrays(vector<int>& a, int target) {
        ll n = a.size(), res = 0;

        vector<ll> f(2 * n + 5, 0), p(2 * n + 5, 0);
        ll off = n + 2, s = 0;

        p[off] = f[off] = 1;
        for (int i = 0; i < n; i++) {
            s += (a[i] == target ? 1 : -1);
            
            res += p[s + off - 1];
            f[s + off]++;
            p[s + off] = p[s + off - 1] + f[s + off];
        }
        return res;
    }
};