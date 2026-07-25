class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), res = 0;

        priority_queue<int> pq;
        for (const auto &c: costs) {
            res += c[0];
            pq.push(c[0] - c[1]);
            if (pq.size() > n / 2) {
                res -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};