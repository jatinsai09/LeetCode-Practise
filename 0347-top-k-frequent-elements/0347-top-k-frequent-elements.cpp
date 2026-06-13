class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        vector<int> res;
        int mx = 0;
        for (const auto& i : nums) {
            mx = max(mx, ++mp[i]);
        }

        vector<vector<int>> b(mx + 1);
        for (auto &[val, freq]: mp) {
            b[freq].push_back(val);
        }

        for (int f = mx; f >= 0; f--) {
            for (auto &i: b[f]) {
                if (res.size() == k) {
                    break;
                }
                res.push_back(i);
            }
        }

        return res;
    }
};