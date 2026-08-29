class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cost = 0;
        queue<pair<int, int>> last7, last30;
        for (const auto& d : days) {
            while (!last7.empty() && last7.front().first < d) {
                last7.pop();
            }
            while (!last30.empty() && last30.front().first < d) {
                last30.pop();
            }

            last7.push({d + 7 - 1, cost + costs[1]});
            last30.push({d + 30 - 1, cost + costs[2]});

            cost = min(
                {cost + costs[0], last7.front().second, last30.front().second});
        }
        
        return cost;
    }
};