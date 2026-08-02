class Solution {
#define ll long long int
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();

        vector<ll> pre(n);
        pre[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + tasks[i];
        }

        vector<int> res(m);
        ll off = 0, s = pre[n - 1];
        for (int i = 0; i < m; i++) {
            int t = shifts[i];
            if (off + t >= s) {
                res[i] = 0;
                off = 0;
            } else {
                int ind = upper_bound(begin(pre), end(pre), t + off) - begin(pre);
                res[i] = n - ind;

                off += t;
            }
        }

        return res;
    }
};