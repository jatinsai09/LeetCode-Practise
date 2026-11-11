class Solution {
#define ll long long 
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll res = 0;
        if (need1 < need2) {
            res = (ll)need1 * min(costBoth, cost1 + cost2);

            res += (ll)(need2 - need1) * min(costBoth, cost2);
        } else {
            res = (ll)need2 * min(costBoth, cost1 + cost2);

            res += (ll)(need1 - need2) * min(costBoth, cost1);
        }

        return res;
    }
};