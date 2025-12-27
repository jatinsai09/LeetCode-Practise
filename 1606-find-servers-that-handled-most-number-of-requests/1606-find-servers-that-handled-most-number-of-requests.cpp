class Solution {
#define pii pair<int, int>
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size();
        vector<int> freq(k);

        set<int> free;
        priority_queue<pii, vector<pii>, greater<pii>> running;

        for (int i = 0; i < k && i < n; i++) {
            running.push({arrival[i] + load[i], i});
            freq[i]++;
        }

        for (int i = k; i < n; i++) {
            while (!running.empty() && running.top().first <= arrival[i]) {
                free.insert(running.top().second);
                running.pop();
            }

            if (!free.empty()) {
                auto server = lower_bound(begin(free), end(free), i % k);

                if (server == free.end()) {
                    server = free.begin();
                }

                running.push({arrival[i] + load[i], *server});
                freq[*server]++;
                free.erase(server);
            }
        }

        int mx = 0;
        for (int i = 0; i < k; i++) {
            mx = max(mx, freq[i]);
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (freq[i] == mx) {
                res.push_back(i);
            }
        }

        return res;
    }
};