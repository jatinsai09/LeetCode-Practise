class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        vector<int> res;
        for (const auto& i : nums) {
            mp[i]++;
        }

        int mps = mp.size();
        priority_queue<pair<int, int>> pq;

        for (auto it = begin(mp); it != end(mp); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > mps - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};