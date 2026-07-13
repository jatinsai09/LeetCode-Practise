class Solution {
#define pii pair<int, int>
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> res;
        priority_queue<pii, vector<pii>, greater<>> pq;

        for (const auto &i : nums1) {
            pq.push({i + nums2[0], 0});
        }

        while (k-- && !pq.empty()) {
            int sum = pq.top().first;
            int pos = pq.top().second;

            res.push_back({sum - nums2[pos], nums2[pos]});
            pq.pop();

            if (pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }
        return res;
    }
};