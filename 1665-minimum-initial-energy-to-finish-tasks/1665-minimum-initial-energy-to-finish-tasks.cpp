class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort (begin(tasks), end(tasks), [&](auto& a, auto& b){
            return a[1] - a[0] > b[1] - b[0];
        });

        int start = tasks[0][1], rem = tasks[0][1] - tasks[0][0];
        int extra = 0;

        for (int i = 1; i < n; i++) {
            int cost = tasks[i][0], limit = tasks[i][1];

            if (rem < limit) {
                extra += limit - rem;
                rem = limit;
            }

            rem -= cost;
        }

        return start + extra;

    }
};