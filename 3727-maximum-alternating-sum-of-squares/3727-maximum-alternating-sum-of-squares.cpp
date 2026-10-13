class Solution {
#define ll long long    
public:
    long long maxAlternatingSum(vector<int>& a) {
        ll n = a.size();
        sort(begin(a), end(a), [&](int a, int b){
            return abs(a) < abs(b);
        });

        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                res -= a[i] * a[i];
            } else {
                res += a[i] * a[i];
            }
        }
        return res;
    }
};