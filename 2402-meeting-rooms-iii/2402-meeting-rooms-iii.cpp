class Solution {
#define ll long long
#define info pair<ll, int>
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));

        vector<int> freq(n);
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        priority_queue<info, vector<info>, greater<info>> running;
        for (const auto& meet : meetings) {
            ll start = meet[0], end = meet[1], dur = end - start;

            while (!running.empty() && running.top().first <= start) {
                free.push(running.top().second);
                running.pop();
            }

            int room;
            if (!free.empty()) {
                room = free.top();
                free.pop();
            } else {
                auto latest = running.top();
                room = latest.second;
                start = latest.first;

                running.pop();
            }
            running.push({(ll)start + dur, room});
            freq[room]++;
        }

        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (freq[i] > freq[ind]) {
                ind = i;
            }
        }

        return ind;
    }
};