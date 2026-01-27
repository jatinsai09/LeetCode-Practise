class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        stations.push_back({target, 0});

        priority_queue<int> pq;
        int cur = startFuel, res = 0;
        for (int i = 0; i <= n; i++) {
            if (cur >= target) {
                return res;
            }

            while (!pq.empty() && cur < stations[i][0]) {
                cur += pq.top();
                pq.pop();
                res++;
            }

            if (cur < stations[i][0]) {
                return -1;
            }

            pq.push(stations[i][1]);
        }

        return res;
    }
};