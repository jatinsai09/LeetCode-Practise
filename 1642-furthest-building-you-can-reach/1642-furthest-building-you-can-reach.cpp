class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = h.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n - 1; i++) {
            int d = h[i + 1] - h[i];
            if (d > 0) {
                pq.push(d);
            }
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0) {
                return i;
            }
        }
        return n - 1;
    }
};