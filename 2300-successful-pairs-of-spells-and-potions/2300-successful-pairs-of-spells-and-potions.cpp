class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = spells.size(), m = potions.size();
        vector<int> pairs(n);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int l = 0, r = m - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                long long p = 1LL * spell * potions[mid];

                if (p >= success) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                
                pairs[i] = m - l;
            }
        }
        return pairs;
    }
};