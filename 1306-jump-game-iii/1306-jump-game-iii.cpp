class Solution {
public:
    bool canReach(vector<int>& arr, int st) {
        int n = arr.size();
        vector<int> vis(n);
        queue<int> q;

        q.push(st);
        vis[st] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (!arr[cur]) {
                return true;
            }

            int l = cur - arr[cur], r = cur + arr[cur];
            if (l >= 0 && !vis[l]) {
                q.push(l);
                vis[l] = 1;
            }
            if (r < n && !vis[r]) {
                q.push(r);
                vis[r] = 1;
            }
        }

        return false;
    }
};