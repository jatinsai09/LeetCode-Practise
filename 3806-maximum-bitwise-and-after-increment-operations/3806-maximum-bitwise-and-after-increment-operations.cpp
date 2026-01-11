class Solution {
#define ll long long    
public:
    int maximumAND(vector<int>& a, int k, int m) {
        int n = a.size(), res = 0;

        for (int b = 30; b >= 0; b--) {
            ll req = res | (1LL << b);

            vector<ll> cost;

            for(auto &i: a) {
                int cur = i, got = 0;

                for (int j = 30; j >= 0; j--) {
                    if (req & (1 << j)) {
                        if (!(cur & (1 << j))) {
                            ll rem = cur % (1LL << j);
                            ll inc = (1LL << j) - rem;

                            got += inc;
                            cur += inc;
                        }
                    }
                }
                cost.push_back(got);
            }
            sort(begin(cost), end(cost));

            ll total = 0;
            for (int i = 0; i < m; i++) {
                total += cost[i];
            }

            if (total <= k) {
                res = req;
            }
        }

        return res;
    }
};