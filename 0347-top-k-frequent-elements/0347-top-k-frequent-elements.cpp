class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        int mx = 0;
        for (const auto& i : nums) {
            mx = max(mx, ++mp[i]);
        }

        vector<vector<int>> b(mx + 1);
        for (const auto &[val, freq]: mp) {
            b[freq].push_back(val);
        }

        vector<int> res;
        for (int f = mx; f > 0 && res.size() < k; f--) {
            for (const auto &val: b[f]) {
                res.push_back(val);
                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};