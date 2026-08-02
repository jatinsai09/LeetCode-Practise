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
                int l = 0, r = n - 1, mid;

                while (l <= r) {
                    mid = l + (r - l) / 2;

                    if (t >= pre[mid] - off) {
                        l = mid + 1; 
                    } else {
                        r = mid - 1;
                    }
                }

                res[i] = n - l;
                off += t;
            }
        }

        return res;
    }
};