class Solution {
#define ll long long int
#define pll pair<ll, ll>
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        ll n = servers.size(), m = tasks.size();

        priority_queue<pll, vector<pll>, greater<>> pq, cur;

        for (ll i = 0; i < n; i++) {
            pq.push({servers[i], i});
        }

        vector<int> res(m);
        ll i, ind, st = 0;
        for (ll j = 0; j < m; j++) {
            st = max(st, j);

            while (!cur.empty() && cur.top().first <= st) {
                i = cur.top().second;
                cur.pop();

                pq.push({servers[i], i});
            }
            
            if (!pq.empty()) {
                ind = pq.top().second;
                pq.pop();

                res[j] = ind;

                cur.push({st + tasks[j], ind});
                continue;
            }

            st = cur.top().first;
            while (!cur.empty() && cur.top().first == st) {
                i = cur.top().second;
                cur.pop();

                pq.push({servers[i], i});
            }

            ind = pq.top().second;
            pq.pop();

            res[j] = ind;

            cur.push({st + tasks[j], ind});
        }

        return res;
    }
};