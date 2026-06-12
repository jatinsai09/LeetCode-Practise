class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0, j = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> ql;
        priority_queue<int, vector<int>, greater<int>> qr;

        long long res = 0;
        while (k--) {
            while (ql.size() < candidates && i <= j) {
                ql.push(costs[i++]);
            }
            while (qr.size() < candidates && i <= j) {
                qr.push(costs[j--]);
            }

            int t1 = !ql.empty() ? ql.top() : INT_MAX;
            int t2 = !qr.empty() ? qr.top() : INT_MAX;

            if (t1 <= t2) {
                res += t1;
                ql.pop();
            } else {
                res += t2;
                qr.pop();
            }
        }

        return res;
    }
};