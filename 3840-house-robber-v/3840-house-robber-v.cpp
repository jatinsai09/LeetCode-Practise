class Solution {
#define ll long long int    
public:
    long long rob(vector<int>& a, vector<int>& cls) {
        ll n = a.size();

        if (n == 1) {
            return a[0];
        }

        ll pick = a[0], not_pick = 0;

        for (int i = 1; i < n; i++) {
            ll pick1 = 0;
            if (cls[i] == cls[i - 1]) {
                pick1 = pick1 + a[i] + not_pick;
            } else {
                pick1 = pick1 + a[i] + max(pick, not_pick);
            }

            ll not_pick1 = max(pick, not_pick);

            pick = pick1;
            not_pick = not_pick1;
        }

        return max(pick, not_pick);
    }
};