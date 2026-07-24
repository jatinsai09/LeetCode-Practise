class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int>& a, int k) {
        int n = a.size(), res = 0, req = k;
        vector<int> cnt(n + 1);

        for (int l = 0, r = 0; r < n; r++) {
            req -= (++cnt[a[r]] == 1);

            while (req < 0) {
                req += (--cnt[a[l++]] == 0);
            }
            res += (r - l + 1);
        }
        return res;
    }
};