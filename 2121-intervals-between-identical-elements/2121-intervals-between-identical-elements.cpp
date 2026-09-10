class Solution {
#define ll long long int
public:
    vector<long long> getDistances(vector<int>& a) {
        ll n = a.size();
        vector<ll> res(n), r1(n), r2(n); 

        unordered_map<ll, ll> prev, f;
        for (int i = 0; i < n; i++) {
            if (prev.count(a[i])) {
                r1[i] = r1[prev[a[i]]] + f[a[i]] * (i - prev[a[i]]);
            }
            prev[a[i]] = i;
            f[a[i]]++;
        }

        f.clear();

        unordered_map<ll, ll> nxt;
        for (int i = n - 1; i >= 0; i--) {
            if (nxt.count(a[i])) {
                r2[i] = r2[nxt[a[i]]] + f[a[i]] * (nxt[a[i]] - i);
            }
            nxt[a[i]] = i;
            f[a[i]]++;
            
            res[i] = r1[i] + r2[i];
        } 
        return res;
    }
};